FROM gcc:11
WORKDIR /APP
COPY . .
RUN g++ Source.cpp -o app.exe

FROM ubuntu:07.06
COPY --from=build /APP/app.exe /app.exe
CMD ./app.exe
