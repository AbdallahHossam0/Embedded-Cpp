SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
MCU = "atmega32"

#optimiazations levels are:
#	O0 -> (No Optimization)
#	O1 -> (Low Optimization)
#	O2 -> (Moderate Optimization)
#	O3 -> (High Optimization)
#	Os -> (Optimize for Size) 
OPT_LEVEL = "O0"

CFLAGS = -mmcu=$(MCU) -$(OPT_LEVEL)
CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums 
CFLAGS += -Wall -g -ggdb
CFLAGS += -ffunction-sections -fdata-sections -Wl,--gc-sections -Wl,--relax

GREEN='\033[0;32m'
RED='\033[0;31m'
END_COLOUR='\033[0m'


all:a.hex

%.o: %.cpp
	@[ -d ./obj ] || mkdir -p ./obj
	@echo "********************************"
	@echo "\033[33mCompiling\033[0m"
	C:/avr8GNUToolChain/bin/avr-g++ $(CFLAGS) -c $< --output ./obj/$@
	@echo "********************************"
	@echo -e ${RED}OBJECT FILES CREATED SUCCESSFULLY${END_COLOUR}
	@echo

a.elf: $(OBJ)
	@[ -d ./bin ] || mkdir -p ./bin
	@echo "********************************"
	C:/avr8GNUToolChain/bin/avr-g++ -Wl,-Map,./obj/AVRtest.map $(CFLAGS) ./obj/$< --output ./bin/$@
	@echo "********************************"
	@echo -e ${RED}ELF FILE CREATED SUCCESSFULLY${END_COLOUR}
	@echo
	
a.hex: a.elf
	@echo "********************************"
	C:/avr8GNUToolChain/bin/avr-objcopy -O ihex ./bin/$< ./bin/$@
	@echo "********************************"
	@echo -e ${RED}HEX FILE CREATED SUCCESSFULLY${END_COLOUR}
	@echo
	@echo "********************************"
	C:/avr8GNUToolChain/bin/avr-objdump -h -S ./bin/a.elf  > ./obj/"Extended List.lss"
	@echo "********************************"
	@echo
	@echo "********************************"
	avr-size --format=avr --mcu=$(MCU) ./bin/a.elf
	@echo -e ${GREEN}BUILD SUCCESSFUL${END_COLOUR}


clear:
	@rm -r ./obj 2>/dev/null || :

clean: clear
	@rm -r ./bin 2>/dev/null || :
