

include $(ROOT)/global.mk
	   
PROJECT = test-x86
TARGET  = $(call OSX,bin/Release/$(PROJECT))

vs2015:    	$(PROJECT).vcxproj
#	"$(VS140COMNTOOLS)vsvars32" && msbuild $(PROJECT).vcxproj
	"$(VS140COMNTOOLS)vsvars32" && msbuild $(PROJECT).vcxproj /p:Configuration=Release

	
vs2005:    	$(PROJECT).vcproj
	"$(VS80COMNTOOLS)vsvars32" && vcbuild $(PROJECT).vcproj

$(TARGET): vs2015
	
.PHONY: run 
	
run:	
	$(TARGET)
	
test: .exitcode
	
.exitcode: $(TARGET) .test.bat
	.test.bat 
	
.test.bat: 
	@echo $(TARGET) >.test.bat
	@echo @echo %%errorlevel%% ^>.exitcode >>.test.bat


$(PROJECT).vcxproj :	premake5.lua 
	premake5 vs2015

	
$(PROJECT).vcproj :	premake5.lua 
	premake5 vs2005

gmake:
	$(CP) Makefile .Makefile.origin
	premake5 gmake --verbose
	$(CP) Makefile .Makefile.premake
	$(CP) .Makefile.origin Makefile
	$(MAKE) -f .Makefile.premake test-x86 verbose=y config=release
	
	
	
	
include $(ROOT)/clean.mk	