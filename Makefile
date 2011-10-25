# Do not modify this file to change flags/options.
# Instead, add custom options to config.default
CONFIG ?= config.default
-include $(CONFIG)

BINARY := mjavac

# Add source files here
SRCS :=
SRCS += src/Main.cpp src/scanner/Scanner.cpp src/scanner/Identifier.cpp src/scanner/Number.cpp src/scanner/Screener.cpp src/scanner/Token.cpp src/scanner/TokenFactory.cpp

OBJS = $(filter %.o, $(SRCS:.c=.o) $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

CCFLAGS += $(CFLAGS)
CCFLAGS += -std=c99

CXXFLAGS += $(CFLAGS)

# use 'make Q=' to show the commands, do not modify this line
Q ?= @

$(BINARY): $(OBJS)
	@echo '===> LD $@'
	$(Q)$(CXX) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

.c.o:
	@echo '===> CC $<'
	$(Q)$(CC) $(CCFLAGS) -c -MMD -o $@ $<

.cc.o:
	@echo '===> CXX $<'
	$(Q)$(CXX) $(CXXFLAGS) -c -MMD -o $@ $<

clean:
	@echo '===> CLEAN'
	$(Q)rm -fr $(DEPS) $(OBJS) $(BINARY)
