#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

typedef struct breakpoints {
	uint16_t breakp;
	bool active;
	struct breakpoints* next;
} breakpoints;

typedef struct cpu8080 {
	uint8_t a;
	uint8_t b;
	uint8_t c;
	uint8_t	d;
	uint8_t	e;
	uint8_t	h;
	uint8_t l;
	bool carry;
	bool one;
	bool parity;
	bool zero1;
	bool aux;
	bool zero2;
	bool zero;
	bool sign;
	uint16_t sp;
	uint16_t pc;
	uint8_t* memory;

	breakpoints* breakpoints;
	bool running;
	bool breaked;
	uint16_t memBeg;	
	uint16_t memEnd;	
	uint16_t codeBeg;	
	uint16_t codeEnd;	
	uint16_t stackBeg;
	bool disasAsExec;
	bool allowInterrupt;
} cpu8080;

#define menuInputSize 20
#define memorySize 0xffff
#define startStack 0x4000
#define memoryOutputFile "memory.dat"


void emulate(cpu8080* cpu);

int disass(cpu8080* cpu, int i);

void auxiliaryFlag(cpu8080* cpu, uint8_t x, uint8_t y, uint8_t z);

void zeroFlag(cpu8080* cpu, uint16_t x);

void signFlag(cpu8080* cpu, uint16_t x);

void parityFlag(cpu8080* cpu, uint16_t x);

void carryFlag(cpu8080* cpu, uint16_t x);

void carryFlagSub(cpu8080* cpu, uint16_t x);

void carryFlag16(cpu8080* cpu, uint32_t x);

void add(cpu8080* cpu, uint8_t x);

void adc(cpu8080* cpu, uint8_t x);

void sub(cpu8080* cpu, uint8_t x);

void sbb(cpu8080* cpu, uint8_t x);

void and(cpu8080* cpu, uint8_t x);

void xor(cpu8080* cpu, uint8_t x);

void or(cpu8080 * cpu, uint8_t x);

void inr(cpu8080* cpu, uint8_t* reg);

void dcr(cpu8080* cpu, uint8_t* reg);

void inx8(uint8_t* x, uint8_t* y);

void inx16(uint16_t* x);

void dcx8(uint8_t* x, uint8_t* y);

void dcx16(uint16_t* x);


void stax(cpu8080* cpu, uint8_t x, uint8_t y);

void ldax(cpu8080* cpu, uint8_t x, uint8_t y);

void mvi(cpu8080* cpu, uint8_t* reg, uint8_t arg);

void lxi(cpu8080* cpu, uint8_t* x, uint8_t* y);

void lxi16(cpu8080* cpu, uint16_t* x);

void dad(cpu8080* cpu, uint8_t* x, uint8_t* y);

void dad16(cpu8080* cpu, uint16_t* z);


void pop(cpu8080* cpu, uint8_t* x, uint8_t* y);

void push(cpu8080* cpu, uint8_t x, uint8_t y);

void push16(cpu8080* cpu, uint16_t x);

void popPsw(cpu8080* cpu);

void cmp(cpu8080* cpu, uint8_t x);

void jmp(cpu8080* cpu, uint8_t x, uint8_t y);

void call(cpu8080* cpu, uint8_t x, uint8_t y);

void ret(cpu8080* cpu);

void rst(cpu8080* cpu, uint16_t x);

uint8_t convertFlagsRegister(cpu8080* cpu);

int uintConvert(uint8_t x, uint8_t y);

int charToInt(char* inp);

char* removeBeginning(char* inp);

int hexDecimaltoInt(char* arg);

void printTwoArgs(cpu8080* cpu, int pc);

void printTwoArgsBack(cpu8080* cpu, int pc);

void setSpecificFlagPsw(cpu8080* cpu, int x, int cmp, bool* flag);

void setCode(cpu8080* cpu, char* code, int size);

void scanBinary(char* fileName, cpu8080* cpu);

long int getFileSize(FILE* fp);

int isBreakPoint(cpu8080* cpu);

breakpoints* findLastBreakpoint(breakpoints* breakpoint);

breakpoints* allocateBreakpoint(uint16_t x);

int checkBreakPoint(breakpoints* breakpt, uint16_t x);

void activateBreakpoint(cpu8080* cpu, char* menuInput);

void createBreakpoint(cpu8080* cpu, char* menuInput);

void deactivateBreakpoint(cpu8080* cpu, char* menuInput);

void disassembleAll(cpu8080* cpu);

void printHelp(void);

void printRegisters(cpu8080* cpu);

void showBreakpoints(breakpoints* breakpoint, int n);

void printFlags(cpu8080* cpu);

void jumpExec(cpu8080* cpu, char* input);

void printMemoryRegions(cpu8080* cpu);

void printRegister(cpu8080* cpu, char* menuInput);

void resetExecution(cpu8080* cpu);

cpu8080* createCpu(void);

void destroyCpu(cpu8080* cpu);

void stepInstruction(cpu8080* cpu);

void toggleDisassExec(cpu8080* cpu);

void dumpMemory(cpu8080* cpu);

void examineMemory(cpu8080* cpu, char* inp);

void resetExecution(cpu8080* cpu);

void set(cpu8080* cpu, char* inp);
