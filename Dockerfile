FROM ubuntu:24.04

RUN apt-get update && \
    apt-get install -y g++

WORKDIR /app

COPY . .

RUN g++ main.cpp -Iinclude -std=c++17 -o WelcomeWebApp

EXPOSE 8080

CMD ["./WelcomeWebApp"]