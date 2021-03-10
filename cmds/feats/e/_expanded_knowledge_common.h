int ret;
mapping srow;
int maxpow, sminpow = 0;

if (!stringp(args)) {
    write("%^YELLOW%^Your current expanded knowlege " + expanded_level + " is %^BLUE%^" + TP->query("expanded_knowledge_" + expanded_level) + "%^YELLOW%^.");
    return 1;
}

if (TP->query("expanded_knowledge_" + expanded_level)) {
    if(TP->query("expanded_knowledge_change")>time()-60*60*24*3)
    {
        write("%^BOLD%^%^BLACK%^Too soon, once per three days, go away.");
        return 1;
    }
}

if (member_array(args, TP->query_mastered_spells("psion") + TP->query_mastered_spells("psywarrior")) != -1) {
    write("%^YELLOW%^You already know %^BLUE%^" + args + "%^YELLOW%^ as mastered spell.");
    return 1;
}

srow = MAGIC_D->query_index_row(args);

if (!mapp(srow)) {
    write("%^YELLOW%^The spell %^BLUE%^" + args + "%^YELLOW%^ can't be found.");
    return 1;
}

maxpow = max(({TP->query_class_level("psion"), TP->query_class_level("psywarrior")}));

if (srow["levels"]["psion"] && srow["levels"]["psywarrior"]) {
    sminpow = min(({srow["levels"]["psion"], srow["levels"]["psywarrior"]}));
} else {
    if (srow["levels"]["psion"]) {
        sminpow = srow["levels"]["psion"];
    }
    if (srow["levels"]["psywarrior"]) {
        sminpow = srow["levels"]["psywarrior"];
    }
}

if (!(sminpow > 0 && sminpow < maxpow)) {
    write("%^YELLOW%^The spell %^BLUE%^" + args + "%^YELLOW%^ is not of appropriate power to be cast as expanded knowledge.");
    return 1;
}

write("%^YELLOW%^You have gained knowledge of %^BLUE%^" + args + "%^YELLOW%^ as of your expanded knowledge " +expanded_level + " power.");

if (TP->query("expanded_knowledge_" + expanded_level)) {
    TP->set("expanded_knowledge_change",time());
}
TP->set("expanded_knowledge_" + expanded_level, args);


return 1;
