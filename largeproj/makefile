SUBDIRS =libs apps
EXESRC = run.cpp

LIBS = $(addsuffix .a, $(SUBDIRS))
.PHONY: project subdirs $(SUBDIRS)

subdirs: $(SUBDIRS)
	mkdir -p obj      
$(SUBDIRS):
	$(MAKE) --directory=$@ $(TARGET)
	cp $@/*.a obj 

project: $(EXESRC)
	echo "$(LIBS)"        
	g++ -L./obj -o $@ -c $^  
	
	


	

        



