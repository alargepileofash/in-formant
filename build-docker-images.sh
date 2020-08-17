#!/bin/bash

cd docker

./download-shaderc.sh

for tag in linux windows macos android; do
    docker build --rm -t clorika/sabuilder:$tag . -f Dockerfile.$tag
    docker tag clorika/sabuilder:$tag docker.io/clorika/sabuilder:$tag
    docker push clorika/sabuilder:$tag
done
