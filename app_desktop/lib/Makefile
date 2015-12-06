DIRS = miscfuncs MouseEvent ScaleData
.PHONY: all clean

all:
	@for d in $(DRIS); \
	do \
		$(MAKE) -C $$d; \
	done

clean:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d clean; \
	done
