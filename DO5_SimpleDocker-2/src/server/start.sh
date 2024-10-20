#!/bin/bash

docker pull nginx

docker build -t server .

docker run --rm -d -p 81:81 --name server nginx

docker cp nginx.conf server:/etc/nginx/
docker cp fcgi_hello.c server:/

docker exec server apt-get update
docker exec server apt-get install -y gcc spawn-fcgi libfcgi-dev
docker exec server gcc ./fcgi_hello.c -l fcgi -o fcgi_server
docker exec server spawn-fcgi -p 8080 fcgi_server
docker exec server nginx -s reload

printf "The sever is up. Press <Enter> to stop it.\n"
read -p "Time to stop? " -r

docker stop server