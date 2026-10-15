FROM gcc:latest

COPY . /usr/src/text

WORKDIR /usr/src/text

RUN make

CMD ["./text", "/test"]
