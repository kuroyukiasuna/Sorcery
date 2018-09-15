CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = sorcery
OBJECTS = main.o airelemental.o appsummoner.o auraofpower.o banish.o blizzard.o bonegolem.o cards.o darkritual.o disenchant.o earthelemental.o enchantments.o enrage.o fireelemental.o giantstrength.o haste.o magicfatigue.o massummoner.o minions.o novpyro.o playboard.o player.o potionseller.o raisedead.o recharge.o rituals.o silence.o spell.o standstill.o unsummon.o display.o ascii_graphics.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean

