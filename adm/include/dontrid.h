#define EXCLUDE_WIZ ({ \
  "adia","amidon","crystal","daketh","firedragon","fizbane", \
  "grayhawk","grazzt","grendel","killashandra","little","lorcus","melnmarn", \
  "mercutio","mortimer","obsidian","pator","pegasus","remo","rotor","sibi", \
  "svaha","thorn","tristan","vetri","garrett","styx","diego","bruenor","korlik",  \
  "saide", "cythera", "nienne", "tsera", "dinji", "circe", "lujke", "ares"})

#define EXCLUDE_AVATAR ({ \
"emilie","mihaan","gorakk","siara","welkanar", \
"anshara", "nsykah", "ingwelessa","akadi","kossuth","grumbar","istishia",\
"auril","cyric","eldath","helm","kelemvor","loviatar","malar","mask",\
"mielikki","mystra","selune","shar", "silvanus", "oghma", "bane", "tymora",\
"tempus","torm","tyr","xvim","sune","beshaba","auppenser","shaundakul","bhaal" })

// The first four in EXCLUDE_AVATAR are newbie personas Nienne made for general use.
#define EXCLUDE_PLAYER ({ \
"arngrym", "alveric","alexander","alfero","aramel",\
"anestriana","andromede","ariel","awana",\
"ambrosia","anna","arbaal","argon","asmodai","azuth","bannic",\
"beowulf","berset","blaxar","bryanna","bregan","candide","chance","embrye","bartholomew",\
"cyclone","cyreen","darkbringer","dread",\
"eiryasha","eventine","feyd","gabriella","galdor","gannaldar",\
"itzana","vrax", "kaean", "kain","kairntelest","kiya", "logos","illusen",\
"lassar","sesshin", "sevotharte","lorilei","meridian","michylia","taislinn",\
"faelyn", "darren", "thayil", "mithras","lukas","richard","vessius", \
"myrrhkael","jaedryl","margath","nightfall","ikki","brenamen","vethor","logos",\
"paige","piezo","rainne","raelith","rygar","saradin","sera",\
"slore","smash","spider","presea",\
"shrydelhi","spungold","stefano","arkhdel","tanamen","tatiania","trevize",\
"tyrion","ungrim","violet","war","sylax","teclan",\
"mosutha","godzilla","klithgor","felgorn","xerxes","roghaf",\
"galdor","aelith","melic","desmond",\
"darkbringer","vrax","gwenhwyfar","ianthe","ziger",\
"torin","seraphim","zeal", "taeryn",  \
"marika", "ulfang", "valadrix", "tiberius",\
"zrikk", "zarcice", "orlic","moonstar","lorath",\
})

#define EXCLUDE ( EXCLUDE_PLAYER + EXCLUDE_WIZ + EXCLUDE_AVATAR )
