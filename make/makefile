define parent
   $(warning  "parent has $1")
   $(call child, $2)
endef

define child
   $(warning "child here $1")
endef

.PHONY: Hello

OBJS = file1.o file3.a file2.o
T = $(filter  %.a, $(OBJS))
P = $(patsubst %.o, %.c, $(OBJS))

Hello:
	$(call parent, one, two)
	@echo "$P"

