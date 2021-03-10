/********************************************************
Instructions:
This file declares all vallid NWPs and their information.
The key is the name, This is the actual string that is used in the proficiency. Ex: "concealment"
"exp percent" this is the number that prepresents the %% of total current nwp exp the player has that will be rewarded for each use of the prof. This number will be divided by 1000 to determine the % ie 20->.2%

classes: This is the list (it must be an array) of classes that this prof applies to. Ex ({"thief"})

stats: This is the list of stats that are key to this prof. See mins for more information. Ex ({"dexterity"})

mins: This is the list of minimum stats in the associated stat, in order to aquire this prof. These also determine the seed. 

base: This is the base exp requirement for seed that will be used to determine the required exp to advance the prof. The base is calculated by adding 100 exp for every point the required stats have below 18 (yes over 18 subtracts 100). If you are in the
required class then the new bsae is divided by 2. Then a bonus is applied (depending on the coder.
Example is concealment below.

Added studying, free for bards.  Circe 5/22/04
*/



#define NWPS_MAP ([\
"concealment":(["exp percent":10,"classes":({"thief"}),"stats":({"dexterity"}),"mins":({14}),"base":400,"free classes":({"thief"})]),\
"healing":(["exp percent":5,"classes":({"cleric","paladin"}),"stats":({"wisdom","intelligence"}),"mins":({12, 12}),"base":600]),\
"healing mount":(["exp percent":10,"classes":({"cleric","paladin"}),"stats":({"wisdom","intelligence"}),"mins":({12, 12}),"base":600,"depend prof":({"healing"}),"prof level":({8})]),\
"fast talking":(["exp percent":1,"classes":({"bard","thief"}),"stats":({"charisma"}),"mins":({13}),"base":2000]),\
"riding":(["exp percent":1,"classes":({"cavalier","paladin","antipaladin"}),"stats":({"wisdom"}),"mins":({10}),"base":900,"free classes":({"paladin","cavalier","antipaladin"})]),\
"writing":(["exp percent":5,"classes":({"cleric","mage", "bard","psion","cavalier","paladin","antipaladin"}),"stats":({"intelligence"}),"mins":({11}),"base":500,"free classes":({"mage"})]),\
"forage":(["exp percent":10,"classes":({"ranger", "mage"}),"stats":({"wisdom","intelligence"}), "mins":({10, 11}),"base":400]),\
"hunting":(["exp percent":15,"classes":({"ranger","fighter", "cavalier", "paladin", "antipaladin"}),"stats":({"wisdom","intelligence"}),"mins":({10, 10}),"base":400]),\
"escape":(["exp percent":10,"classes":({"bard","thief"}),"stats":({"intelligence","dexterity"}),"mins":({11,13}),"base":600]),\
"skinning":(["exp percent":5,"classes":({"ranger"}),"stats":({"intelligence"}),"mins":({10}),"base":600]),\
"tailoring":(["exp percent":5,"classes":({}),"stats":({"dexterity"}),"mins":({10}),"base":600]),\
"jewelling":(["exp percent":5,"classes":({}),"stats":({"dexterity","intelligence"}),"mins":({10,10}),"base":600]),\
"armorsmithing":(["exp percent":5,"classes":({"fighter"}),"stats":({"intelligence"}),"mins":({12}),"base":600]),\
"weaponsmithing":(["exp percent":5,"classes":({"fighter"}),"stats":({"intelligence"}),"mins":({12}),"base":600]),\
"tracking":(["exp percent":2, "classes":({"ranger"}), "stats":({"wisdom"}), "mins":({10}),"base":300,"free classes":({"ranger"})]),\
"eavesdropping":(["exp percent":5,"classes":({"bard", "thief"}), "stats":({"intelligence"}), "mins":({12}), "base":400]),\
"studying":(["exp percent":7,"classes":({"bard", "thief", "mage", "psion"}), "stats":({"intelligence"}), "mins":({14}), "base":400,"free classes":({"bard","psion"})]),\
"disguise":(["exp percent":9,"classes":({ "thief"}), "stats":({"charisma"}), "mins":({7}), "base":400,"free classes":({"bard"})]),\
])
