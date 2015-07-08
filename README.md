Spruce Wristband
===

Particle io ( Former Spark Core ) device for notifying a person by a haptic motor and an OLED display.

For url requests
`curl https://api.particle.io/v1/devices/{{deviceId}}/{{command}} -d access_token={{accessToken}} -d args={{data}}`

args can be passed in and can container `\n` to print to a new line

Args is a set up to take one argument of the [String datatype](http://docs.particle.io/core/firmware/#language-syntax-string-class). This argument length is limited to a max of 63 characters.

Parts
===
* Spark Core : http://www.adafruit.com/products/2127
* OLED: http://www.adafruit.com/products/938
* Motor: http://www.adafruit.com/products/1201?gclid=CjwKEAjw8e2sBRCYte6U3suRjFESJAB4gn_g5usF5ULbKwbj6e92krjzB_TGcuYndYlyDwRvr_jMbRoCUtLw_wcB
* Battery Charge Controller: http://www.browndoggadgets.com/products/lithium-battery-charge-controller
* Battery: http://www.all-battery.com/3.7V700mAhLIPORechargeableBattery-34078.aspx?utm_source=GoogleShopping&utm_medium=GDF&gdftrk=gdfV26767_a_7c354_a_7c922_a_7c34078&gclid=CjwKEAjw8e2sBRCYte6U3suRjFESJAB4gn_gV0q1ttWvMCo_TitHSSwyWNA3O1zkvq38ni6tpiWQnxoCHzTw_wcB