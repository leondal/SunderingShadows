//updated by Circe 4/16/04 for new gods
//Added Sune, Shaundakul, and Beshaba - Cythera 8/05
//Added ranger deity restrictions - Nienne 02/07
//Loviatar removed following NF plot stuffs - Nienne 09/07.
//Anhur added by ~Circe~ 5/17/08 - will go in after Tiamat's plot
//Modified DIETIES definition for layman follower alignments, per 2e Faiths and Avatars.  Required modifications to /d/shadowgate/masters/masters.c and /std/temple.c - Octothorpe 4/4/10

#define KNIGHTS ({"auril","auppenser","bane","grumbar","helm","kelemvor","kossuth","lathander","mystra","selune","shar","sune","torm","tyr"})

/*#define DIETIES (([\
   "akadi":({"Elemental Air",({1,2,3,4,5,6,7,8,9}),({4,5,6,7,8,9})}),\
   "anhur":({"Vindication/Storms",({1,4,5,7,8}),({4,7,8})}),\  
   "auppenser":({"Mentalism/Psionics",({1,2,3,4,5,6,7,8,9}),({2,4,5,6,8})}),\
   "auril":({"Cold/Ice",({2,3,5,6,8,9}),({3,6,9})}),\
   "bane":({"Tyranny/Fear",({2,3,5,6,9}),({2,3,6})}),\
   "beshaba":({"Misfortune",({3,5,6,8,9}),({6,8,9})}),\
   "cyric":({"Deception/Illusion",({3,5,6,8,9}),({6,8,9})}),\
   "grumbar":({"Elemental Earth",({1,2,3,4,5,6,7,8,9}),({1,2,3,4,5,6})}),\
   "helm":({"Guardians",({1,2,3,4,5,6}),({1,2,3})}),\
   "istishia":({"Elemental Water",({1,2,3,4,5,6,7,8,9}),({4,5,6,7,8,9})}),\
   "kelemvor":({"Death",({1,2,3,4,5,6,7,8,9}),({1,2,3,5})}),\
   "kossuth":({"Elemental Fire",({1,2,3,4,5,6,7,8,9}),({1,2,3,4,5,6})}),\
   "lathander":({"Renewal/Sun",({1,2,4,5,7,8}),({1,4,7})}),\
   "malar":({"Hunters/Bloodlust",({3,5,6,8,9}),({3,6,9})}),\
   "mask":({"Shadows/Intrigue",({2,3,4,5,6,7,8,9}),({2,3,5,6,8,9})}),\
   "mielikki":({"Forests",({1,2,4,5,7,8}),({1,4,5,7})}),\
   "mystra":({"Magic",({1,2,3,4,5,6,7,8,9}),({1,2,3,5})}),\
   "oghma":({"Knowledge",({1,2,3,4,5,6,7,8,9}),({2,4,5,6,8})}),\
   "selune":({"Seekers/Moon",({1,4,5,7,8}),({1,4,7,8})}),\
   "shar":({"Darkness/Loss",({2,3,5,6,8,9}),({3,6,9})}),\
   "shaundakul":({"Travel/Trade",({4,5,6,7,8,9}),({5,7,8,9})}),\
   "silvanus":({"Animal/Plant",({2,4,5,6,8}),({2,5,8})}),\
   "sune":({"Love/Beauty",({1,2,4,5,7,8}),({1,4,7,8})}),\
   "talos":({"Destruction",({3,5,6,8,9}),({6,8,9})}),\
   "tempus":({"War/Strength",({1,2,3,4,5,6,7,8,9}),({7,8,9})}),\
   "torm":({"Protection",({1,2,4,7}),({1,2,4})}),\
   "tymora":({"Good Fortune",({1,4,5,7,8}),({4,7,8})}),\
   "tyr":({"Justice",({1,2,4}),({1,2,4})}),\
   "jarmila":({"Light/Love",({1,2,4}),({1,2,4,5,7})}),\
]))*/

#define NEWPANTHEON ({"jarmila","callamir","kreysneothosies","ryorik","lord shadow","the faceless one","kismet","lysara","nimnavanon"})

#define DIETIES (([\
   "jarmila":({"Light/Love",({1,2,4,5,7}),({1,4,7})}),\
   "callamir":({"Luck/Trickery",({1,4,5,7,8}),({4,7,8})}),\
   "kreysneothosies":({"Justice/Protection",({1,2,4,5,7}),({1,2,4})}),\
   "ryorik":({"Elements/Destruction",({2,4,5,6,7,8,9}),({5,7,8,9})}),\
   "lord shadow":({"Darkness/Tyranny",({2,3,5,6,9}),({2,3,6})}),\
   "nilith":({"Undeath/War",({3,5,6,8,9}),({3,6,8,9})}),\        
   "the faceless one":({"Murder/Deception",({3,5,6,8,9}),({3,6,8,9})}),\
   "kismet":({"Magic/Knowledge",({1,2,3,4,5,6,7,8,9}),({1,2,3,4,5,6,7,8,9})}),\
   "lysara":({"Death/Fate",({1,2,3,4,5,6,7,8,9}),({2,4,5,6,8})}),\
   "nimnavanon":({"Forests/Weather",({2,4,5,6,7,8}),({4,5,6,7,8})}),\
]))

// KNIGHTALIGN and RANGERALIGN have been weeded out as they were just duplicated data.
// also MONKS, RANGERS and DRUIDS should not be in use; MONKS use clergy aligns and 
// rangers/druids are no longer god limited. Still, leaving them all here just in case! N, 3/17.

#define KNIGHTALIGN (([\
   "auppenser":({"Mentalism/Psionics",({2,4,5,6,8})}),\
   "auril":({"Cold/Ice",({3,6,9})}),\
   "bane":({"Tyranny/Fear",({2,3,6})}),\
   "grumbar":({"Elemental Earth",({1,2,3,4,5,6})}),\
   "helm":({"Guardians",({1,2,3})}),\
   "kelemvor":({"Death",({1,2,3})}),\
   "kossuth":({"Elemental Fire",({1,2,3,4,5,6})}),\
   "lathander":({"Renewal/Sun",({1,4,7})}),\
   "mystra":({"Magic",({1,2,3})}),\
   "selune":({"Seekers/Moon",({4,7,8})}),\
   "shar":({"Darkness/Loss",({3,6,9})}),\
   "sune":({"Love/Beauty",({1,4,7,8})}),\
   "torm":({"Protection",({1,2,4})}),\
   "tyr":({"Justice",({1,2,4})}),\
]))

#define RANGERALIGN (([\
   "akadi":({"Elemental Air",({4,5,6,7,8,9})}),\
   "anhur":({"Vindication/Storms",({4,7,8})}),\
   "auril":({"Cold/Ice",({3,6,9})}),\
   "grumbar":({"Elemental Earth",({1,2,3,4,5,6})}),\
   "istishia":({"Elemental Water",({4,5,6,7,8,9})}),\
   "kelemvor":({"Death",({1,2,3})}),\
   "kossuth":({"Elemental Fire",({1,2,3,4,5,6})}),\
   "lathander":({"Renewal/Sun",({1,4,7})}),\
   "malar":({"Hunters/Bloodlust",({3,6,9})}),\
   "mielikki":({"Forests",({1,4,5,7})}),\
   "selune":({"Seekers/Moon",({4,7,8})}),\
   "shar":({"Darkness/Loss",({3,6,9})}),\
   "shaundakul":({"Travel/Trade",({5,7,8,9})}),\
   "silvanus":({"Animal/Plant",({2,5,8})}),\
   "talos":({"Destruction",({6,8,9})}),\
   "tempus":({"War/Strength",({7,8,9})}),\
   "tyr":({"Justice",({1,2,4})}),\
]))
