FROM gcc:11
WORKDIR APP1
COPY . .
RUN g++ Source.cpp -o app_cc.exe
ENTRYPOINT ./app_cc.exe
