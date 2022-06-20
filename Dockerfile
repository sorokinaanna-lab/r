FROM gcc:11
WORKDIR APP1
COPY . .
RUN g++ Source.cpp -o app.exe
ENTRYPOINT ./app.exe