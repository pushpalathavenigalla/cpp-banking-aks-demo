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
            transform:translateY(-5px);
        }

        .icon{
            width:55px;
            height:55px;
            background:#0078D4;
            border-radius:50%;

            display:flex;
            justify-content:center;
            align-items:center;

            margin-bottom:15px;
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
            margin-bottom:25px;
        }

        footer{
            background:#003366;
            color:white;
            padding:20px;
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
            <div class="icon">
                <svg width="28" height="28" viewBox="0 0 24 24" fill="white">
                    <path d="M21 7H3V17H21V7ZM19 15H5V9H19V15ZM7 11H10V13H7V11Z"/>
                </svg>
            </div>

            <h3>Check Balance</h3>
            <p>
                View your available account balance securely and instantly.
            </p>
        </div>

        <div class="card">
            <div class="icon">
                <svg width="28" height="28" viewBox="0 0 24 24" fill="white">
                    <path d="M19 11H13V5H11V11H5V13H11V19H13V13H19V11Z"/>
                </svg>
            </div>

            <h3>Deposit Money</h3>
            <p>
                Deposit money into your account quickly and securely.
            </p>
        </div>

        <div class="card">
            <div class="icon">
                <svg width="28" height="28" viewBox="0 0 24 24" fill="white">
                    <path d="M19 11H5V13H19V11Z"/>
                </svg>
            </div>

            <h3>Withdraw Money</h3>
            <p>
                Withdraw available funds from your account at any time.
            </p>
        </div>

        <div class="card">
            <div class="icon">
                <svg width="28" height="28" viewBox="0 0 24 24" fill="white">
                    <path d="M7 7L3 11L7 15V12H14V10H7V7ZM17 17L21 13L17 9V12H10V14H17V17Z"/>
                </svg>
            </div>

            <h3>Transfer Funds</h3>
            <p>
                Transfer money between accounts in a secure manner.
            </p>
        </div>

        <div class="card">
            <div class="icon">
                <svg width="28" height="28" viewBox="0 0 24 24" fill="white">
                    <path d="M14 2H6C4.9 2 4 2.9 4 4V20L8 16H14C15.1 16 16 15.1 16 14V4C16 2.9 15.1 2 14 2Z"/>
                </svg>
            </div>

            <h3>Transaction History</h3>
            <p>
                View your complete account transaction history.
            </p>
        </div>

        <div class="card">
            <div class="icon">
                <svg width="28" height="28" viewBox="0 0 24 24" fill="white">
                    <path d="M12 12C14.21 12 16 10.21 16 8C16 5.79 14.21 4 12 4C9.79 4 8 5.79 8 8C8 10.21 9.79 12 12 12ZM12 14C9.33 14 4 15.34 4 18V20H20V18C20 15.34 14.67 14 12 14Z"/>
                </svg>
            </div>

            <h3>Account Details</h3>
            <p>
                Manage and view customer profile information.
            </p>
        </div>

    </div>

    <div class="status">
        Banking Services Available
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