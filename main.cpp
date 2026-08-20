#include "crow.h"
#include <cstdlib>
#include <string>

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
    ([]()
    {
        return R"(
        <html>
        <head>
            <title>Azure Welcome Page</title>
            <style>
                body {
                    text-align: center;
                    font-family: Arial;
                    margin-top: 100px;
                    background-color: #f4f4f4;
                }

                h1 {
                    color: blue;
                }
            </style>
        </head>
        <body>
            <h1>Welcome to Azure Deployment Demo</h1>
            <h2>C++ Web Application</h2>
            <p>Successfully hosted on Azure App Service</p>
        </body>
        </html>
        )";
    });

    // Health check endpoint for Azure
    CROW_ROUTE(app, "/health")
    ([]()
    {
        return crow::response(200, "OK");
    });

    const char* portEnv = std::getenv("PORT");
    int port = portEnv ? std::stoi(portEnv) : 8080;

    app.port(port)
       .bindaddr("0.0.0.0")
       .multithreaded()
       .run();
}