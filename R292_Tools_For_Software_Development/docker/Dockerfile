FROM gcc:latest

COPY . /usr/src/hello-world

WORKDIR /usr/src/hello-world

RUN g++ -o hello-world main.cpp (ili neki make)

ENTRYPOINT ["./program"]

CMD ["default_arg_if_none_specified"]
