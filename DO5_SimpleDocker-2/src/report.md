## Part 1. Готовый докер

1) Взяла официальный докер-образ с nginx и скачала его при помощи docker pull<br>
    - ```docker pull nginx```<br>
    ![alt text](./forDock/1.png)


2) Проверка наличия докер-образа через <br>```docker images```<br>
    ![alt text](./forDock/2.png)

3) Запуск докер-образ через docker run -d [image_id|repository].<br> 

    - ```docker run -d nginx```<br>
    ![alt text](./forDock/3.png)<br>

4) Провека, что образ запустился через <br>```docker ps```<br>
    ![alt text](./forDock/4.png)<br>

5) Посмотрела информацию о контейнере через docker inspect [container_id|container_name]. По выводу команды определила размер контейнера, список замапленных портов и ip контейнера.<br> 
    - ```размер контейнера``<br>
        ![alt text](./forDock/5.png)<br>
    <br> 
    - ```список замапленных портов``<br>
        ![alt text](./forDock/7.png)<br>
     <br> 
    - ```ip контейнера``<br>
        ![alt text](./forDock/6.png)<br>

6) Остановила докер образ через <br>```docker stop [container_id|container_name]```<br> 
    - ```docker stop aa011ad8e8ed```<br>
    ![alt text](./forDock/8.png)<br>

7) Проверка, что образ остановился через docker ps
    ![alt text](./forDock/9.png)<br>

8) Запуск докер с портами 80 и 443 в контейнере, замапленными на такие же порты на локальной машине, через команду run.
    - ```docker run -d -p 80:80 -p 443:443 nginx```<br>
    ![alt text](./forDock/10.png)<br>

9) Проверка, что в браузере по адресу localhost:80 доступна стартовая страница nginx.
    ![alt text](./forDock/11.png)<br>

10) Перезапуск докер контейнера
    - ```docker restart```<br>
    ![alt text](./forDock/12.png)<br>

11) Проверка, что контенер запустился
    - ```docker ps```<br>
    ![alt text](./forDock/13.png)<br>

## Part 2. Операции с контейнером

1) Чтение файла nginx.conf внутри докер контейнера через команду exec<br>
    - ```docker exec -it 6c4b9ad8c111 cat /etc/nginx/nginx.conf```<br>
    ![alt text](./forDock/14.png)

2) Создание на локальной машине файла nginx.conf и настройка в нем по пути /status отдачи страницы статуса сервера nginx.
    ![alt text](./forDock/15.png)

3) Копирование файла nginx.conf внутрь докер-образ.<br> 
    - ```docker cp nginx.conf 6c4b9ad8c111:/etc/nginx/nginx.conf```<br>
    ![alt text](./forDock/16.png)<br>

4) Перезапуск nginx внутри докер-образа.
    - ```docker exec -it 6c4b9ad8c111 nginx -s reload```<br>
    ![alt text](./forDock/17.png)<br>

5) По адресу localhost:80/status отдается страничка со статусом сервера nginx.
    ![alt text](./forDock/18.png)<br>

6) Экспорт контейнера в файл container.tar.
    - ```docker export 6c4b9ad8c111 -o container.tar```<br>
    ![alt text](./forDock/19.png)<br>

7) Остановка контейнера.
    
    ![alt text](./forDock/20.png)<br>

8) Удаление образа.
    - ```docker rmi```<br>
    ![alt text](./forDock/21.png)<br>

9) Удаление остановленного контейнера.
    
    ![alt text](./forDock/22.png)<br>

10) Импорт контейнера.
    - ```docker import container.tar my-nginx-image```<br>
    ![alt text](./forDock/23.png)<br>

11) Запуск импортированного контейнера.
    - ```docker run -d -p 80:80 -p 443:443 my-nginx-image nginx```<br>
    ![alt text](./forDock/24.png)<br>

12) По адресу localhost:80/status отдается страничка со статусом сервера nginx.
    ![alt text](./forDock/25.png)<br>

## Part 3. Операции с контейнером

1) Мини-сервер на C и FastCgi, который будет возвращать простейшую страничку с надписью Hello World!. Файл с исходным кодом лежит в папке server.
    ![alt text](./forDock/26.png)

2) Запуск мини-сервера через spawn-fcgi на порту 8080.
    - ```Сначала компилируем программу через gcc```<br>
    ![alt text](./forDock/27.png)<br>
    - ```Затем запускаем серевер через spawn```<br>
    ![alt text](./forDock/28.png)<br>

3) nginx.conf, который будет проксировать все запросы с 81 порта на 127.0.0.1:8080.<br> 
    ![alt text](./forDock/29.png)<br>

4) Проверка, что в браузере по localhost:81 отдается написанная страничка.
    ![alt text](./forDock/30.png)<br>

5) Перенос nginx.conf по пути ./nginx/nginx.conf.
    ![alt text](./forDock/31.png)<br>

## Part 4. Свой докер

1) Написала свой докер-образ, который:

    1) собирает исходники мини сервера на FastCgi из Части 3;

    2) запускает его на 8080 порту;

    3) копирует внутрь образа написанный ./nginx/nginx.conf;

    4) запускает nginx.
Он лежит в папке part4.

2) Сборка написанного докер-образа.
    ![alt text](./forDock/32.png)

3) Проверка через docker images, что все собралось корректно.
    ![alt text](./forDock/33.png)<br>

4) Запуск докер-образа с маппингом 81 порта на 80 на локальной машине и маппингом папки ./nginx внутрь контейнера по адресу, где лежат конфигурационные файлы nginx'а.
    ![alt text](./forDock/34.png)<br>

5) По localhost:80 доступна страничка написанного мини сервера.
    ![alt text](./forDock/35.png)<br>

6) В ./nginx/nginx.conf было дописано проксирование странички /status (он лежит в папке part4), и после перезапуска образа по localhost:80/status отдается страничка со статусом nginx.
    ![alt text](./forDock/36.png)<br>

## Part 5. Dockle

Образ был просканирован, ошибки исправлены, также для упрощения запуска был написан файл launch_part5.sh. Он автоматически собирает образ и проверяет его через dockle. Достаточно его запустить:
    ![alt text](./forDock/37.png)<br>

## Part 6. Docker Compose

1) Был написан файл docker-compose.yml, с помощью которого:

    1) Поднимается докер-контейнер из Части 5.
    2) Поднимается докер-контейнер с nginx, который проксирует все запросы с 8080 порта на 81 порт первого контейнера.

Он лежит в папке part6.

2) Замапила 8080 порт второго контейнера на 80 порт локальной машины.
    
    ![alt text](./forDock/38.png)<br>

3) Остановила все запущенные контейнеры.
    ![alt text](./forDock/39.png)<br>

4) Соберка и запуск проекта.
    - ```docker-compose build```<br>
    ![alt text](./forDock/40.png)<br>
    - ```docker-compose up```<br>
    ![alt text](./forDock/41.png)<br>

5) В браузере по localhost:80 отдается написанная страничка, как и ранее.
    ![alt text](./forDock/42.png)<br>