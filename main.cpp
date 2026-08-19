#include "crow.h"

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

    app.port(8080).multithreaded().run();
}