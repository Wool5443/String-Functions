TARGET=main
CC=g++

CFLAGS=-D _DEBUG -ggdb3 -std=c++17 -O0 -Wno-pointer-arith -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr

HEADERS=-I./headers/

MAIN_SRC_FOLDER=src/
MAIN_OBJ_FOLDER=obj/

MAIN_SRCS=$(wildcard $(MAIN_SRC_FOLDER)*.cpp) main.cpp
OBJS=$(patsubst $(MAIN_SRC_FOLDER)%.cpp,$(MAIN_OBJ_FOLDER)%.o,$(MAIN_SRCS))

DEPENDENCIES=Utils/
DEPENDENCIES_OBJ_FOLDER=depObj/

DEPENDENCIES_SRC_FOLDERS=$(foreach dir,$(DEPENDENCIES),$(dir)src/)
HEADERS+=$(foreach dir,$(DEPENDENCIES),-I./$(dir)headers/)

DEPENDENCIES_SRCS=$(foreach dir,$(DEPENDENCIES_SRC_FOLDERS),$(wildcard $(dir)*.cpp))

DEPENDENCIES_OBJS_TEMP=$(foreach src,$(DEPENDENCIES_SRCS),$(DEPENDENCIES_OBJ_FOLDER)$(notdir $(src)))
DEPENDENCIES_OBJS+=$(DEPENDENCIES_OBJS_TEMP:.cpp=.o)

$(TARGET) : $(OBJS) $(DEPENDENCIES_OBJS)
	$(CC) $(HEADERS) $(CFLAGS) $^ -o $@

$(MAIN_OBJ_FOLDER)%.o : $(MAIN_SRC_FOLDER)%.cpp
	$(CC) $(HEADERS) $(CFLAGS) -c $^ -o $@

$(DEPENDENCIES_OBJ_FOLDER)%.o : $(DEPENDENCIES_SRCS)
	$(CC) $(HEADERS) $(CFLAGS) -c $^ -o $@

clean :
	rm $(TARGET) $(MAIN_OBJ_FOLDER)*.o $(DEPENDENCIES_OBJS)*.o