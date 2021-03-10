//updated by Circe 4/16/04 for new gods
//Added Sune, Shaundakul, and Beshaba - Cythera 8/05
//Added ranger deity restrictions - Nienne 02/07
//Loviatar removed following NF plot stuffs - Nienne 09/07.
//Anhur added by ~Circe~ 5/17/08 - will go in after Tiamat's plot
//Modified DIETIES definition for layman follower alignments, per 2e Faiths and Avatars.  Required modifications to /d/shadowgate/masters/masters.c and /std/temple.c - Octothorpe 4/4/10

//#define DRUIDS ({"eldath", "mielikki"})

//#define KNIGHTS ({"grumbar","helm","xvim","kossuth","lathander","mystra","selune","torm","tyr"})

#define KNIGHTS ({"auppenser","grumbar","helm","kelemvor","kossuth","lathander","mystra","selune","torm","tyr","shar","auril","bane","sune"})

// Added Auril & Shar because I do think they make sense.

#define RANGERS ({"akadi","anhur","auril","grumbar","istishia","kelemvor","kossuth","lathander","malar","mielikki","selune","shar","shaundakul","talos","tempus","tyr"})

#define DRUIDS ({ "akadi","auril","grumbar","istishia","lathander","malar","mielikki","selune","shaundakul","talos" })

#define DIETIES (([\
   "akadi":({"Elemental Air",({1,2,3,4,5,6,7,8,9}),({4,5,6,7,8,9})}),\
   "anhur":({"Vindication/Storms",({1,2,4,5,7,8}),({1,4,7,8})}),\
   "auril":({"Cold/Ice",({2,3,5,6,8,9}),({3,6,9})}),\
   "auppenser":({"Mentalism/Psionics",({1,2,3,4,5,6,7,8,9}),({1,2,3,4,5,6,7,8,9})}),\
   "bane":({"Tyranny/Fear",({2,3,5,6,8,9}),({3,6,9})}),\
   "beshaba":({"Misfortune",({1,2,3,4,5,6,7,8,9}),({6,8,9})}),\
   "cyric":({"Deception/Illusion",({2,3,5,6,8,9}),({3,6,9})}),\
   "grumbar":({"Elemental Earth",({1,2,3,4,5,6,7,8,9}),({1,2,3,4,5,6})}),\
   "helm":({"Guardians",({1,2,4,5,7,8}),({1,2,5})}),\
   "istishia":({"Elemental Water",({1,2,3,4,5,6,7,8,9}),({4,5,6,7,8,9})}),\
   "kelemvor":({"Death",({1,2,3,4,5,6,7,8,9}),({1,2,4,5})}),\
   "kossuth":({"Elemental Fire",({1,2,3,4,5,6,7,8,9}),({1,2,3,4,5,6})}),\
   "lathander":({"Renewal/Sun",({1,2,4,5,7,8}),({1,2,4,7})}),\
   "malar":({"Hunters/Bloodlust",({3,5,6,8,9}),({3,6,9})}),\
   "mask":({"Shadows/Intrigue",({2,3,4,5,6,7,8,9}),({2,3,5,6,8,9})}),\
   "mielikki":({"Forests",({1,2,4,5,7,8}),({1,4,5,7})}),\
   "mystra":({"Magic",({1,2,3,4,5,6,7,8,9}),({1,2,3,4,5,7,8})}),\
   "oghma":({"Knowledge",({1,2,3,4,5,6,7,8,9}),({1,2,4,5,7,8})}),\
   "selune":({"Seekers/Moon",({1,2,4,5,7,8}),({1,2,4,5,7,8})}),\
   "shar":({"Darkness/Loss",({1,2,3,4,5,6,7,8,9}),({3,6,9})}),\
   "shaundakul":({"Travel/Trade",({1,2,4,5,7,8}),({4,5,7,8})}),\
   "sune":({"Love/Beauty",({1,2,4,5,7,8}),({1,2,4,5,7,8})}),\
   "talos":({"Destruction",({2,3,5,6,8,9}),({3,6,8,9})}),\
   "tempus":({"War/Strength",({1,2,3,4,5,6,7,8,9}),({1,2,3,4,6,7,8,9})}),\
   "torm":({"Protection",({1,2,4,7}),({1,4,7})}),\
   "tymora":({"Good Fortune",({1,2,3,4,5,6,7,8,9}),({4,5,7,8})}),\
   "tyr":({"Justice",({1,2,4}),({1,2})}),\
]))

#define KNIGHTALIGN (([\
   "auppenser":({"Mentalism/Psionics",({1,2,3,4,5,6,7,8,9})}),\
   "auril":({"Cold/Ice",({3,6,9})}),\
   "bane":({"Tyranny/Fear",({3,6})}),\
   "grumbar":({"Elemental Earth",({1,2,3,4,5,6})}),\
   "helm":({"Guardians",({1,2,5})}),\
   "kelemvor":({"Death",({1,2,4,5})}),\
   "kossuth":({"Elemental Fire",({1,2,3,4,5,6})}),\
   "lathander":({"Renewal/Sun",({1,2,4,7})}),\
   "mystra":({"Magic",({1,2,3,4,5,7,8})}),\
   "selune":({"Seekers/Moon",({1,2,4,5,7,8})}),\
   "shar":({"Darkness/Loss",({3,6,9})}),\
   "sune":({"Love/Beauty",({1,4,7,8})}),\
   "torm":({"Protection",({1,4,7})}),\
   "tyr":({"Justice",({1,2,4})}),\
]))

#define RANGERALIGN (([\
   "akadi":({"Elemental Air",({4,5,6,7,8,9})}),\
   "anhur":({"Vindication/Storms",({4,7,8})}),\
   "auril":({"Cold/Ice",({3,6,9})}),\
   "grumbar":({"Elemental Earth",({1,2,3,4,5,6})}),\
   "istishia":({"Elemental Water",({4,5,6,7,8,9})}),\
   "kelemvor":({"Death",({1,2,4,5})}),\
   "kossuth":({"Elemental Fire",({1,2,3,4,5,6})}),\
   "lathander":({"Renewal/Sun",({1,2,4,7})}),\
   "malar":({"Hunters/Bloodlust",({3,6,9})}),\
   "mielikki":({"Forests",({1,4,5,7})}),\
   "selune":({"Seekers/Moon",({1,2,4,5,7,8})}),\
   "shar":({"Darkness/Loss",({3,6,9})}),\
   "shaundakul":({"Travel/Trade",({2,5,7,8})}),\
   "talos":({"Destruction",({3,6,8,9})}),\
   "tempus":({"War/Strength",({1,2,3,4,6,7,8,9})}),\
   "tyr":({"Justice",({1,2,4})}),\
]))