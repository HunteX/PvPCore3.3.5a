    /*******************************************************************************************
    *                                                __                           __ _                                                         *
    *                                         /\ \ \___  _ __ ___  ___  ___  / _| |_                                                           *
    *                                        /  \/ / _ \| '_ ` _ \/ __|/ _ \| |_| __|                                                          *
    *                                       / /\  / (_) | | | | | \__ \ (_) |  _| |_                                                           *
    *                                       \_\ \/ \___/|_| |_| |_|___/\___/|_|  \__|       - www.Nomsoftware.com -    *
    *                               The policy of Nomsoftware states: Releasing our software   *
    *                               or any other files are protected. You cannot re-release    *
    *                               anywhere unless you were given permission.                 *
    *                           (C) Nomsoftware 'Nomsoft' 2011-2012. All rights reserved.      *
    ********************************************************************************************/
    /*********************************************************
      *                      Title:                        *
       *             TrinityCore C++ Teleporter                       *
            *                                                                *
             *            Scripted by: Faded                *
              *     (C)Nomsoftware 'Nomsoft' 2012          *
               *-----------------------------------------*/
     
    #include "ScriptPCH.h"
     
    enum eMenus
    {
            MY_CITIES_MENU                  = 1,
            NVM_EXIT                                = 2,
            PLAYER_MENU                             = 3,
            HEAL_MENU                               = 4,
            BUFF_MENU                               = 5,
            CUSTOM_AREAS_MENU               = 6,
            REZ_MENU                                = 7,
            CUSTOM_LOCATION_PORT    = 8,
            A_CITIES_MENU                   = 9,
            H_CITIES_MENU                   = 10,
            DARNASSUS_PORT                  = 11,
            THE_EXODAR_PORT                 = 12,
            STORMWIND_PORT                  = 13,
            IRONFORGE_PORT                  = 14,
            ORGRIMMAR_PORT                  = 15,
            THUNDER_BLUFF_PORT              = 16,
            UNDERCITY_PORT                  = 17,
            SILVERMOON_CITY_PORT    = 18,
            MY_LOCATIONS_MENU               = 19,
            SERVICES_MENU                   = 20,
            DALARAN_PORT                    = 21,
            SHATTRATH_CITY_PORT             = 22
    };
     
    enum eIcons
    {
            CHAT_ICON                       = 0,
            VENDOR_ICON             = 1,
            FLIGHT_ICON             = 2,
            TRAINER_ICON            = 3,
            GEAR_ICON                       = 4,
            GEAR_ICON_2             = 5,
            BANK_ICON                       = 6,
            CHAT_DOTS_ICON          = 7,
            TABARD_ICON             = 8,
            SWORDS_ICON             = 9,
            GOLD_DOT_ICON           = 10
    };
     
    /* Gossip Colors */
    #define TEXT_CUSTOM_ORANGE                      "|cff873600"
    #define TEXT_CUSTOM_RED                         "|cffA40000"
    #define TEXT_CUSTOM_BLUE                        "|cff00479E"
    #define TEXT_CUSTOM_GREEN                       "|cff065600"
    #define TEXT_CUSTOM_PURPLE                      "|cff5A005B"
    #define TEXT_CUSTOM_GREY                        "|cff515151"
    #define TEXT_CUSTOM_CYAN                        "|cff005853"
    #define TEXT_CUSTOM_BROWN                       "|cff584200"
    /* Gossip Strings */
    #define IN_COMBAT                                       " Leave combat first!"
    #define SERVICES_GOSSIP                         " -> Services"
    #define MY_LOCATIONS_GOSSIP                     " -> Cities"
     
    /* Add your own locations */
    #define CUSTOM_AREAS_GOSSIP                     " -> PvP Zone" //Add your own custom title
    #define CUSTOM_LOCATION_GOSSIP          " -> Gurubashi Arena" //Add your own custom location
     
    #define PLAYER_SERVICES                         " -> Player Services"
    #define NVM_GOSSIP                                      " Nevermind..."
    #define GO_BACK_GOSSIP                          " ...Go Back"
    #define BUFF_ME_GOSSIP                          " -> Buff Me!"
    #define HEAL_ME_GOSSIP                          " -> Heal Me!"
    #define REMOVE_REZ_GOSSIP                       " -> Remove Ressurection Debuff"
    #define CITIES_GOSSIP                           " -> My Cities"
    /* Alliance Cities */
    #define DARNASSUS_GOSSIP                " -> Transmogrification Place"
    #define IRONFORGE_GOSSIP                " -> Ironforge"
    #define STORMWIND_GOSSIP                        " -> Mall"
    #define THE_EXODAR_GOSSIP                       " -> Arena Que Zone"
    /* Horde Cities */
    #define ORGRIMMAR_GOSSIP                        " -> Arena Que Zone"
    #define SILVERMOON_CITY_GOSSIP          " -> Silvermoon City"
    #define THUNDER_BLUFF_GOSSIP            " -> Transmogrifiaction Place"
    #define UNDERCITY_GOSSIP                        " -> Mall"
    #define DALARAN_GOSSIP                          " -> Proffesion Place"
    #define SHATTRATH_CITY_GOSSIP           " -> Duel Zone"
     
    class tc_teleporter : public CreatureScript
    {
            public:
                    tc_teleporter()
                            : CreatureScript("tc_teleporter")
                            {}
     
                            bool OnGossipHello(Player* player, Creature* creature)
                            {
                                    player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_BLUE SERVICES_GOSSIP, GOSSIP_SENDER_MAIN, SERVICES_MENU);
                                    player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, TEXT_CUSTOM_RED NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
                                    player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                    return true;
                            }
                           
                            bool OnGossipSelect(Player* player, Creature* creature, uint32 Sender, uint32 Actions)
                            {
                     player->PlayerTalkClass->ClearMenus();
     
                                     if (player->isInCombat())
                                     {
                                             creature->MonsterWhisper(IN_COMBAT, LANG_UNIVERSAL, NULL);
                                             return false;
                                     }
                                   
                                     if(Sender == GOSSIP_SENDER_MAIN)
                                     {
                                            switch(Actions)
                                            {
                                                    case SERVICES_MENU:
                                                            player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_BLUE MY_LOCATIONS_GOSSIP, GOSSIP_SENDER_MAIN, MY_LOCATIONS_MENU);
                                                            player->ADD_GOSSIP_ITEM(SWORDS_ICON, TEXT_CUSTOM_ORANGE PLAYER_SERVICES, GOSSIP_SENDER_MAIN, PLAYER_MENU);
                                                            player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, TEXT_CUSTOM_RED NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
                                                            player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                                                    break;
                                   
                                                    case MY_LOCATIONS_MENU:
                                                            if(player->GetTeam() == ALLIANCE){
                                                                    player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, GO_BACK_GOSSIP, GOSSIP_SENDER_MAIN, SERVICES_MENU);
                                                                    player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_CYAN CITIES_GOSSIP, GOSSIP_SENDER_MAIN, A_CITIES_MENU);
                                                                    player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_GREEN CUSTOM_AREAS_GOSSIP, GOSSIP_SENDER_MAIN, CUSTOM_AREAS_MENU);
                                                                    player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, TEXT_CUSTOM_RED NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
                                                                    player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                                                            }else{
                                                                    player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, GO_BACK_GOSSIP, GOSSIP_SENDER_MAIN, SERVICES_MENU);
                                                                    player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_CYAN CITIES_GOSSIP, GOSSIP_SENDER_MAIN, H_CITIES_MENU);
                                                                    player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_GREEN CUSTOM_AREAS_GOSSIP, GOSSIP_SENDER_MAIN, CUSTOM_AREAS_MENU);
                                                                    player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, TEXT_CUSTOM_RED NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
                                                                    player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                                                    }break;
                                                   
                                                    case CUSTOM_AREAS_MENU:
                                                            player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, GO_BACK_GOSSIP, GOSSIP_SENDER_MAIN, SERVICES_MENU);
                                                            player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_BLUE CUSTOM_LOCATION_GOSSIP, GOSSIP_SENDER_MAIN, CUSTOM_LOCATION_PORT);
                                                            //Add more custom locations here
                                                            player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, TEXT_CUSTOM_RED NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
                                                            player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                                                    break;
                                                   
                                                    case PLAYER_MENU:
                                                            player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, GO_BACK_GOSSIP, GOSSIP_SENDER_MAIN, SERVICES_MENU);
                                                            player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_BROWN BUFF_ME_GOSSIP, GOSSIP_SENDER_MAIN, BUFF_MENU);
                                                            player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_GREEN HEAL_ME_GOSSIP, GOSSIP_SENDER_MAIN, HEAL_MENU);
                                                            player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_BLUE REMOVE_REZ_GOSSIP, GOSSIP_SENDER_MAIN, REZ_MENU);
                                                            player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, TEXT_CUSTOM_RED NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
                                                            player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                                                    break;
                                                   
                                                    case A_CITIES_MENU:
                                                            player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, GO_BACK_GOSSIP, GOSSIP_SENDER_MAIN, SERVICES_MENU);
                                                            player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_BLUE DALARAN_GOSSIP, GOSSIP_SENDER_MAIN, DALARAN_PORT);
                                                            player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_BLUE DARNASSUS_GOSSIP, GOSSIP_SENDER_MAIN, DARNASSUS_PORT);
                                                            player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_BLUE IRONFORGE_GOSSIP, GOSSIP_SENDER_MAIN, IRONFORGE_PORT);
                                                            player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_BLUE SHATTRATH_CITY_GOSSIP, GOSSIP_SENDER_MAIN, SHATTRATH_CITY_PORT);
                                                            player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_BLUE STORMWIND_GOSSIP, GOSSIP_SENDER_MAIN, STORMWIND_PORT);
                                                            player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_BLUE THE_EXODAR_GOSSIP, GOSSIP_SENDER_MAIN, THE_EXODAR_PORT);
                                                            player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, TEXT_CUSTOM_RED NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
                                                            player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                                                    break;
     
                                                    case H_CITIES_MENU:
                                                            player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, GO_BACK_GOSSIP, GOSSIP_SENDER_MAIN, SERVICES_MENU);
                                                            player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_ORANGE DALARAN_GOSSIP, GOSSIP_SENDER_MAIN, DALARAN_PORT);
                                                            player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_ORANGE ORGRIMMAR_GOSSIP, GOSSIP_SENDER_MAIN, ORGRIMMAR_PORT);
                                                            player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_ORANGE SHATTRATH_CITY_GOSSIP, GOSSIP_SENDER_MAIN, SHATTRATH_CITY_PORT);
                                                            player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_ORANGE SILVERMOON_CITY_GOSSIP, GOSSIP_SENDER_MAIN, SILVERMOON_CITY_PORT);
                                                            player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_ORANGE THUNDER_BLUFF_GOSSIP, GOSSIP_SENDER_MAIN, THUNDER_BLUFF_PORT);
                                                            player->ADD_GOSSIP_ITEM(FLIGHT_ICON, TEXT_CUSTOM_ORANGE UNDERCITY_GOSSIP, GOSSIP_SENDER_MAIN, UNDERCITY_PORT);
                                                            player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, TEXT_CUSTOM_RED NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
                                                            player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                                                    break;
                                                   
                                                    case NVM_EXIT:
                                                            player->PlayerTalkClass->SendCloseGossip();
                                                    break;
                                                   
                                                    case CUSTOM_LOCATION_PORT:
                                                        player->TeleportTo(0, -13261.555664, 163.497223, 35.992432, 4.283933);
                                                        player->PlayerTalkClass->SendCloseGossip();
                                                    break;
                                                   
                                                    case DALARAN_PORT:
                                                            player->TeleportTo(1, -6933.288086f, -4915.037598f, 0.714902f, 4.708452f);
                                                            player->PlayerTalkClass->SendCloseGossip();
                                                    break;
                                                   
                                                    case SHATTRATH_CITY_PORT:
                                                            player->TeleportTo(0, -4248.310059f, -3325.095459f, 231.959869f, 4.653796f);
                                                            player->PlayerTalkClass->SendCloseGossip();
                                                    break;
                                                   
                                                    case DARNASSUS_PORT:
                                                            player->TeleportTo(1, 9949.559570f, 2284.20996f, 1342.969482f, 1.595870f);
                                                            player->PlayerTalkClass->SendCloseGossip();
                                                    break;
                                                   
                                                    case IRONFORGE_PORT:
                                                            player->TeleportTo(0, -4108.489746f, -1397.591675f, 180.133575f, 6.030600f);
                                                            player->PlayerTalkClass->SendCloseGossip();
                                                    break;
                                                   
                                                    case STORMWIND_PORT:
                                                            player->TeleportTo(1, -11852.586914f, -4838.486816f, 9.331769f, 0.921275f);
                                                            player->PlayerTalkClass->SendCloseGossip();
                                                    break;
                                                   
                                                    case THE_EXODAR_PORT:
                                                            player->TeleportTo(530, -855.770020f, 6997.636230f, 34.994953f, 1.067743f);
                                                            player->PlayerTalkClass->SendCloseGossip();
                                                    break;
                                                   
                                                    case ORGRIMMAR_PORT:
                                                            player->TeleportTo(530, -855.770020f, 6997.636230f, 34.994953f, 1.067743f);
                                                            player->PlayerTalkClass->SendCloseGossip();
                                                    break;
                                                   
                                                    case SILVERMOON_CITY_PORT:
                                                            player->TeleportTo(1, 6528.465332f, -4070.930908f, 658.677490f, 1.804462f);
                                                            player->PlayerTalkClass->SendCloseGossip();
                                                    break;
                                                   
                                                    case THUNDER_BLUFF_PORT:
                                                            player->TeleportTo(1, -1277.369995f, 124.804001f, 134.094009f, 5.222740f);
                                                            player->PlayerTalkClass->SendCloseGossip();
                                                    break;
                                                   
                                                    case UNDERCITY_PORT:
                                                            player->TeleportTo(0, -4108.489746f, -1397.591675f, 180.133575f, 6.030600f);
                                                            player->PlayerTalkClass->SendCloseGossip();
                                                    break;
                                                   
                                                    case HEAL_MENU:
                                                    {
                                                            uint32 currentHp = player->GetHealth();
                                                            uint32 maximumHp = player->GetMaxHealth();
                                                           
                                                            if (currentHp == maximumHp)
                                                                    creature->MonsterWhisper("Bah, you have full health. Dont waste my time!", player->GetGUID());
                                                            else{
                                                                    player->SetHealth(maximumHp);
                                                                    player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
                                                                    creature->MonsterWhisper("You have been healed!", player->GetGUID());
                                                                    }
                                                            player->PlayerTalkClass->SendCloseGossip();
                                                    }break;
                                                   
                                                    case BUFF_MENU:
                                                    {
                                                            creature->MonsterWhisper("Do you feel any more buff?", player->GetGUID());
                                                            player->PlayerTalkClass->SendCloseGossip();
                                                            player->CastSpell(player, 35874, true);
                                                            player->CastSpell(player, 35912, true);
                                                            player->CastSpell(player, 38734, true);
                                                    }break;
                                                   
                                                    case REZ_MENU:
                                                    {
                                                            if (player->HasAura(15007))
                                                            {
                                                                    player->RemoveAura(15007);
                                                                    creature->MonsterWhisper("You have been cured.", player->GetGUID());
                                                            }else
                                                                    creature->MonsterWhisper("You would have to be sick first...", player->GetGUID());
                                                                    player->PlayerTalkClass->SendCloseGossip();
                                                    }break;
                                            }
                                    }
                                    return true;
                            }
    };
     
    void AddSC_tc_teleporter()
    {
            new tc_teleporter();
    }
