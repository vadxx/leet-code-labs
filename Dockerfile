FROM ubuntu:24.04

#  Avoid interactive prompts during installation
ENV DEBIAN_FRONTEND=noninteractive

RUN apt update -y && apt install -y --no-install-recommends \
    bash cmake ccache git \
    ninja-build clang lldb clangd libclang-rt-dev \
    python3 python3-venv python3-pip python3-dev

# fix colors
ENV TERM=xterm-256color
ENV COLORTERM=truecolor
RUN sed -i 's/#force_color_prompt=yes/force_color_prompt=yes/' /etc/skel/.bashrc \
    && sed -i 's/#force_color_prompt=yes/force_color_prompt=yes/' /root/.bashrc 2>/dev/null || true

WORKDIR /root

# Base project to develop inside the container
COPY algs-cpp /root/algs-cpp