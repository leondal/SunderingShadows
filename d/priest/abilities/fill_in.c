// Pator@ShadowGate
// April 16 1996
// Replace variable-tags in druidic textstrings

// There has to be a general guideline for druidic texts.
// It will be as follows (for the time bein' of course)
// 1) All text will start with a line with all the type of
//    tags that are in the text, BUT fist the number of tags is given.
//    The format is **<NUMBER_OF_TAGS>**&TAG1&**......**&TAGn&**
// 2) These tags are read and the necesary replacements are made
#include <druids.h>

string fill_in(string txt);

string fill_in(string txt) {
string *tmp,str1,str2;
int i,size;
// JUST FOR TESTING FIRST
     tmp = ({ });
     if (sscanf(txt,"**<%d>**%s",size,str1) == -1)
          { return 0; }
     txt = str1;
     for (i=0;i<size;i++) {
          if (sscanf(str1,"&%s&%s",str2, str1) == -1)
             { break; }
          else { tmp += ({ str2 }) ; } }
          // All the MUD levels are converted to DRUID_LEVELS
          // This is done 'cause these levels may vary in time
          // The DruidMaster must be at least an Elder in
          // the current situation, but 2 months ago this
          // was developer. As is the ArcaneDruid level :
          // It is creator now, due to a lack of high level
          // druids at the moment but I want to raise this
          // to developer atleast in future.
     if (member_array("LEVEL$",tmp)) {
     replace_string(txt,"%%LEVEL$[6]%%",LEVEL_STRING[6]);
     replace_string(txt,"%%LEVEL$[5]%%",LEVEL_STRING[5]);     
     replace_string(txt,"%%LEVEL$[4]%%",LEVEL_STRING[4]);     
     replace_string(txt,"%%LEVEL$[3]%%",LEVEL_STRING[3]);     
     replace_string(txt,"%%LEVEL$[2]%%",LEVEL_STRING[2]);     
     replace_string(txt,"%%LEVEL$[1]%%",LEVEL_STRING[1]);     
     replace_string(txt,"%%LEVEL$[0]%%",LEVEL_STRING[0]);   }
          // Here the ranknames are filled in. This should
          // be a straight-forward mapping, but since I
          // don't know if we get more ranks within the
          // druid class or that we'll change some names
          // I choose this solution so only the druids.h
          // has to be changed. I advise all druid coders
          // to use the RANKING[#]-mapping for all the 
          // druidic code they produce !
     if (member_array("RANK$",tmp)) {
     replace_string(txt,"%%RANK$[6]%%",RANK_STRING[6]);
     replace_string(txt,"%%RANK$[5]%%",RANK_STRING[5]);     
     replace_string(txt,"%%RANK$[4]%%",RANK_STRING[4]);     
     replace_string(txt,"%%RANK$[3]%%",RANK_STRING[3]);     
     replace_string(txt,"%%RANK$[2]%%",RANK_STRING[2]);     
     replace_string(txt,"%%RANK$[1]%%",RANK_STRING[1]);     
     replace_string(txt,"%%RANK$[0]%%",RANK_STRING[0]); }    
          // Here all the materials of the amulets are stored.
          // Also as with the other subsections : There is no
          // guarantee that the materials will change, so 
          // we use this methode. It is very clobbering
          // but it will work eventually. :-)
     if (member_array("AMULET$",tmp)) {
     replace_string(txt,"%%AMULET$[6]%%",AMULET_MATERIAL[6]);
     replace_string(txt,"%%AMULET$[5]%%",AMULET_MATERIAL[5]);     
     replace_string(txt,"%%AMULET$[4]%%",AMULET_MATERIAL[4]);     
     replace_string(txt,"%%AMULET$[3]%%",AMULET_MATERIAL[3]);     
     replace_string(txt,"%%AMULET$[2]%%",AMULET_MATERIAL[2]);     
     replace_string(txt,"%%AMULET$[1]%%",AMULET_MATERIAL[1]);     
     replace_string(txt,"%%AMULET$[0]%%",AMULET_MATERIAL[0]);  }  

     return txt;
}
