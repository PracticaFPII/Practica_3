#----------------------------------------------------------------------
# Opciones para la generacion de codigo
#----------------------------------------------------------------------
CCFLAGS := -Wall -gdwarf-3 -O0 -I./include

#----------------------------------------------------------------------
# MAKE comandos
#----------------------------------------------------------------------
ordenacion.exe : main.c source/busqueda.c source/ordenacion.c source/test_busqueda.c source/test_ordenacion.c source/vector.c
	mingw32-gcc $(CCFLAGS) main.c source/busqueda.c source/ordenacion.c source/test_busqueda.c source/test_ordenacion.c source/vector.c -o ordenacion.exe	
	

#----------------------------------------------------------------------
# otros comandos - CLEAN y DEBUG (con gdb)
#----------------------------------------------------------------------
clean : 
	@echo Recuerda que esto no siempre es necesario antes de hacer un make
	@sleep 5
	@rm -fv ordenacion.exe

debug : ordenacion.exe
	start gdb ordenacion.exe