#!/bin/bash

echo "This the current weather city for NYC"

weather=$(curl -s "curl -s https://api.weather.gov/gridpoints/OKX/34,34/forecast | jq '.properties.periods[0].temperature, .properties.periods[0].temperatureUnit' | paste -sd " )

echo "The weather for $city is $weather"




