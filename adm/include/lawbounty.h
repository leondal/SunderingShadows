#define SAVE_FILE "/adm/save/daemons/lawbounty"
#define ALIGND "/d/tharis/monsters/alignment_d.c"
#define MAX_REQUESTS 40
#define DELAY 432000        //72 hours in seconds
#define DELAY2 172800
#define NUM_JURORS 8

//Statuses
#define NO_REPLY 1
#define WAIT_JURORS 2
#define APPEAL 3


                                                                                 
//Set this value to 1 for race based magistrate, 2 for alignment based magistrate
#define align_or_race_based 1


//Votes is the number of votes a person needs for a bounty, higher means harder to get a bounty.
//  It is the number needed out of the value NUM_JURORS to convict.  (currently 8)
//  default: 4

//Kills is added to the 'alive' value, so a +ve value keeps the player from ketting killed,
//  while a -ve value tries to get them dead.  Default: 0

//juror is the base percent that a magistrate has for selecting someone of a race for
//  jury duty.  This can be influenced by alignment and maybe other factors.
//  default:100

//can_accuse is a boolean for whether or not the person can log a bounty request
//  default:1 (true)

//acc_cost is the amount that it costs that race to place a bounty
//  default:1000

//bribe_cost is the ammount that it would take to bribe the magistrate
//  default:10000

//No magistrate likes people that don't reply to the accuzation
#define RACISMS (([\
    "beastman"  :((["votes":4, "kills":0, "juror":80, "can_accuse":1, "acc_cost":1000, "bribe_cost":10000])),\
    "bugbear"   :((["votes":3, "kills":-1, "juror":10, "can_accuse":0, "acc_cost":1000, "bribe_cost":10000])),\
    "drow"      :((["votes":2, "kills":-3, "juror":2, "can_accuse":0, "acc_cost":1000, "bribe_cost":10000])),\
    "dwarf"     :((["votes":4, "kills":0, "juror":95, "can_accuse":1, "acc_cost":1000, "bribe_cost":10000])),\
    "elf"       :((["votes":5, "kills":0, "juror":100, "can_accuse":1, "acc_cost":1000, "bribe_cost":10000])),\
    "half-drow" :((["votes":3, "kills":-2, "juror":20, "can_accuse":0, "acc_cost":1000, "bribe_cost":10000])),\
    "half-elf"  :((["votes":4, "kills":0, "juror":95, "can_accuse":1, "acc_cost":1000, "bribe_cost":10000])),\
    "firbolg"   :((["votes":4, "kills":0, "juror":80, "can_accuse":1, "acc_cost":1000, "bribe_cost":10000])),\
    "gnoll"     :((["votes":3, "kills":-1, "juror":10, "can_accuse":0, "acc_cost":1000, "bribe_cost":10000])),\
    "gnome"     :((["votes":4, "kills":0, "juror":80, "can_accuse":1, "acc_cost":1000, "bribe_cost":10000])),\
    "goblin"    :((["votes":3, "kills":-2, "juror":10, "can_accuse":0, "acc_cost":1000, "bribe_cost":10000])),\
    "halfling"  :((["votes":4, "kills":0, "juror":80, "can_accuse":1, "acc_cost":1000, "bribe_cost":10000])),\
    "hobgoblin" :((["votes":3, "kills":-1, "juror":10, "can_accuse":0, "acc_cost":1000, "bribe_cost":10000])),\
    "human"     :((["votes":6, "kills":2, "juror":100, "can_accuse":1, "acc_cost":1000, "bribe_cost":10000])),\
    "kobold"    :((["votes":3, "kills":-2, "juror":10, "can_accuse":0, "acc_cost":1000, "bribe_cost":10000])),\
    "ogre"      :((["votes":2, "kills":-2, "juror":10, "can_accuse":0, "acc_cost":1000, "bribe_cost":10000])),\
    "half-ogre" :((["votes":4, "kills":0, "juror":50, "can_accuse":1, "acc_cost":1000, "bribe_cost":10000])),\
    "ogre-mage" :((["votes":4, "kills":0, "juror":30, "can_accuse":1, "acc_cost":1000, "bribe_cost":10000])),\
    "orc"       :((["votes":4, "kills":0, "juror":40, "can_accuse":1, "acc_cost":1000, "bribe_cost":10000])),\
    "half-orc"  :((["votes":4, "kills":0, "juror":60, "can_accuse":1, "acc_cost":1000, "bribe_cost":10000])),\
    "voadkyn"   :((["votes":4, "kills":0, "juror":75, "can_accuse":1, "acc_cost":1000, "bribe_cost":10000])),\
    "wemic"     :((["votes":4, "kills":0, "juror":60, "can_accuse":1, "acc_cost":1000, "bribe_cost":10000])),\
    "unborn"    :((["votes":3, "kills":0, "juror":10, "can_accuse":1, "acc_cost":1000, "bribe_cost":10000])),\
]))

//The lower, the more the magistrate leans towards good.
//  default: 5

#define GE_ALIGN 2
//The lower, the more the magistrate leans towards lawful.
//  default:5

#define LAW_ALIGN 2


