#!/bin/bash

value=false

echo "Hello what time does your meeting end ? (HH:MM AM/PM) format"
echo "Here is an example $(date +"%I:%M %p")"
read time

echo "Are you using zoom or teams ?"
read client 



while [ "$value" = false ]; do
    if [[ "$(date +"%I:%M %p")" == $time ]]; then
        value=true
        kill -9 $(pgrep $client)
    fi

    sleep 60
done
