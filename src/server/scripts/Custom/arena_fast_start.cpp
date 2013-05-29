#include "ScriptPCH.h"
#include "Player.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include <sstream> 

class fast_arena_start : public GameObjectScript
{
    public:

        fast_arena_start() : GameObjectScript("fast_arena_start")
        { }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            if (Battleground *bg = player->GetBattleground())
                if (bg->isArena())
                    ChatHandler(player->GetSession()).PSendSysMessage("Players clicked: %u", bg->ClickFastStart(player, go));

            return false;
        }
};

void AddSC_fast_arena_start()
{
    new fast_arena_start();
}
