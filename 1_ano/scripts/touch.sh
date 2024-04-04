
get_id=$(xinput list | grep "ETPS/2 Elantech Touchpad" | cut -d '=' -f '2' | cut -f 1)

xinput set-button-map $get_id 1 0 3
xinput set-prop $get_id "libinput Scrolling Pixel Distance" 50
xinput set-prop $get_id "libinput Accel Speed" 0.55
