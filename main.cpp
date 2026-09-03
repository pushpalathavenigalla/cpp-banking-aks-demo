#include "crow.h"
#include <cstdlib>
#include <string>
#include <iostream>

int main()
{
    crow::SimpleApp app;

    std::cout << "=================================" << std::endl;
    std::cout << "Application Started Successfully" << std::endl;
    std::cout << "Azure Deployment Demo Running" << std::endl;
    std::cout << "=================================" << std::endl;

    CROW_ROUTE(app, "/")
    ([]()
    {
        std::cout << "[INFO] Home Page Accessed" << std::endl;

        return R"(
<!DOCTYPE html>
<html>
<head>
    <title>Azure Welcome Page</title>

    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f4f4f4;
            text-align: center;
            margin: 0;
            padding: 0;
        }

        .header {
            background-color: #0078D4;
            color: white;
            padding: 30px;
        }

        .container {
            margin-top: 30px;
        }

        .card {
            display: inline-block;
            width: 220px;
            min-height: 180px;
            margin: 10px;
            padding: 20px;
            background: white;
            border-radius: 10px;
            box-shadow: 0px 2px 8px rgba(0,0,0,0.2);
            vertical-align: top;
        }

        .card h2 {
            color: #0078D4;
            margin-top: 0;
        }

        .status {
            margin-top: 30px;
            font-size: 22px;
            color: green;
            font-weight: bold;
        }

        footer {
            margin-top: 40px;
            padding: 20px;
            background: #0078D4;
            color: white;
        }
    </style>
</head>

<body>

    <div class="header">
        <h1>Welcome to Azure Deployment Demo</h1>
        <h3>C++ Web Application</h3>
    </div>

    <div class="container">

        <div class="card">
            <h2>1. Push Code</h2>
            <p>
                Push source code, Dockerfile and YAML files
                into Azure Repos.
            </p>
        </div>

        <div class="card">
            <h2>2. Pipeline</h2>
            <p>
                Azure Pipeline builds the application
                and creates the Docker image.
            </p>
        </div>

        <div class="card">
            <h2>3. Release</h2>
            <p>
                Deploy the latest container image
                to the target environment.
            </p>
        </div>

        <div class="card">
            <h2>4. AKS</h2>
            <p>
                Azure Kubernetes Service runs
                the containerized application.
            </p>
        </div>

        <div class="card">
            <h2>5. Monitoring</h2>
            <p>
                Monitor pod health, application logs
                and deployment status.
            </p>
        </div>

        <div class="status">
            Successfully Hosted on Azure Kubernetes Service
        </div>

    </div>

    <footer>
        Azure Repos → Pipeline → Release → AKS → Monitoring
    </footer>

</body>
</html>
        )";
    });

    // Health Check Endpoint
    CROW_ROUTE(app, "/health")
    ([]()
    {
        std::cout << "[HEALTH] Health Check Accessed" << std::endl;
        return crow::response(200, "OK");
    });

    const char* portEnv = std::getenv("PORT");
    int port = portEnv ? std::stoi(portEnv) : 8080;

    std::cout << "[INFO] Server listening on port "
              << port << std::endl;

    app.port(port)
       .bindaddr("0.0.0.0")
       .multithreaded()
       .run();

    return 0;
}
