FROM ubuntu:24.04

#  Avoid interactive prompts during installation
ENV DEBIAN_FRONTEND=noninteractive

RUN apt update -y && apt install -y --no-install-recommends \
    bash cmake ninja-build clang lldb ccache git clangd \
    python3 python3-venv python3-pip python3-dev

ENV TERM=xterm-256color
ENV COLORTERM=truecolor

WORKDIR /root

# Base project to develop inside the container
COPY algs-cpp /root/algs-cpp