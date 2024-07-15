# invoke SourceDir generated makefile for app_ble.pem3
app_ble.pem3: .libraries,app_ble.pem3
.libraries,app_ble.pem3: package/cfg/app_ble_pem3.xdl
	$(MAKE) -f F:\Work\upwork\CC2640R2\MUX_ADC\adc_mux\simple_adc_cc2640r2lp_app\TOOLS/src/makefile.libs

clean::
	$(MAKE) -f F:\Work\upwork\CC2640R2\MUX_ADC\adc_mux\simple_adc_cc2640r2lp_app\TOOLS/src/makefile.libs clean

