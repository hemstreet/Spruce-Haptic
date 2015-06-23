Spruce Wristband
===

Code for notifying a person by a haptic motor and an OLED display via socket connection

For url requests
`curl https://api.particle.io/v1/devices/{{deviceId}}/{{command}} -d access_token={{accessToken}} -d args={{data}}`
`curl https://api.particle.io/v1/devices/{{deviceId}}/{{command}} -d access_token={{accessToken}} -d args=Para-Black,10.5,1`

A cloud function is set up to take one argument of the [String datatype](http://docs.particle.io/core/firmware/#language-syntax-string-class). This argument length is limited to a max of 63 characters.