#include "crow.h"
#include <cstdlib>
#include <string>
#include <iostream>

int main()
{
    crow::SimpleApp app;

    std::cout << "=================================" << std::endl;
    std::cout << "Banking Application Started" << std::endl;
    std::cout << "C++ Banking Application Running" << std::endl;
    std::cout << "=================================" << std::endl;

    CROW_ROUTE(app, "/")
    ([]()
    {
        std::cout << "[INFO] Home Page Accessed" << std::endl;

        return R"(

<!DOCTYPE html>
<html>
<head>
    <title>Banking Application</title>

    <style>

        *{
            box-sizing:border-box;
        }

        body{
            font-family:Arial,sans-serif;
            background:#f4f7fb;
            margin:0;
            padding:0;
            text-align:center;
        }

        .header{
            background:linear-gradient(135deg,#003366,#0078D4);
            color:white;
            padding:30px;
        }

        .header h1{
            margin-bottom:5px;
        }

        .header h3{
            margin-top:0;
            font-weight:normal;
        }

        .container{
            width:90%;
            margin:30px auto;

            display:grid;
            grid-template-columns:repeat(3,1fr);
            gap:25px;
        }

        .card{
            background:white;
            border-radius:15px;
            padding:20px;
            text-align:left;

            box-shadow:0 4px 12px rgba(0,0,0,0.15);

            transition:transform 0.3s ease;
        }

        .card:hover{
            transform:translateY(-6px);
        }

        .icon{
            font-size:40px;
            margin-bottom:12px;
        }

        .card h3{
            color:#0078D4;
            margin-top:0;
            margin-bottom:10px;
        }

        .card p{
            color:#555;
            line-height:1.5;
        }

        .status{
            font-size:22px;
            color:green;
            font-weight:bold;
            margin-top:10px;
            margin-bottom:20px;
        }

        footer{
            background:#003366;
            color:white;
            padding:20px;
            margin-top:20px;
        }

    </style>
</head>

<body>

    <div class="header">
        <h1>Welcome to Banking Application</h1>
        <h3>C++ Application</h3>
    </div>

    <div class="container">

        <div class="card">
            <div class="icon">💰</div>
            <h3>Check Balance</h3>
            <p>
                View your available account balance securely and instantly.
            </p>
        </div>

        <div class="card">
            <div class="icon">➕</div>
            <h3>Deposit Money</h3>
            <p>
                Deposit money into your account quickly and securely.
            </p>
        </div>

        <div class="card">
            <div class="icon">💸</div>
            <h3>Withdraw Money</h3>
            <p>
                Withdraw available funds from your account at any time.
            </p>
        </div>

        <div class="card">
            <div class="icon">🔄</div>
            <h3>Transfer Funds</h3>
            <p>
                Transfer money between accounts in a secure manner.
            </p>
        </div>

        <div class="card">
            <div class="icon">📄</div>
            <h3>Transaction History</h3>
            <p>
                View your complete account transaction history.
            </p>
        </div>

        <div class="card">
            <div class="icon">👤</div>
            <h3>Account Details</h3>
            <p>
                Manage and view customer profile information.
            </p>
        </div>

    </div>

    <div class="status">
        ✅ Banking Services Available
    </div>

    <footer>
        Secure Banking System | C++ Banking Application
    </footer>

</body>
</html>

        )";
    });

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