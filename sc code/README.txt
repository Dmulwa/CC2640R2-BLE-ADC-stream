After testing and going through your schematic, this is what I found out:

1. The best possible way is to disable input scaling which is 1408/4095 to 1.48.
2. Make sure the signals in Channel 11 and 12 are NO GREATER THAT 1.49V, otherwise may damage the chip.

This is the SC code, I am available today to integrate to CCS if you are available.