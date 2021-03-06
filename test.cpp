#include "doctest.h"
#include "sources/Game.hpp"
#include "sources/Leauge.hpp"
#include "sources/Schedule.hpp"
#include "sources/Score.hpp"
#include "sources/Team.hpp"
#include "sources/iterator.hpp"


#include <string>
#include <iostream>
#include <assert.h>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

TEST_CASE("Good tests"){
    cout << "========================================== Start testing ==========================================\n";

    /* ============
     * Init check
     * ============*/
    SUBCASE("Init check"){
        Leauge* leauge = new Leauge();
        Team* team;
        std::vector<std::string> names;
        for (int i = 0; i < TEAMS_SIZE; i++)
        {
            team = &(*leauge)[i];
            cout << "Name:" << team->get_name() <<" Losses: " << team->get_losses() << " winings: " << team->get_wins() << " skill lvl: "<<  team->get_skill_lvl() << "\n";
            // Verify all the names are diffrent
            assert(find(names.begin(), names.end(), team->get_name()) == names.end());
            assert(team->get_losses() == 0 && team->get_wins() == 0 && team->get_skill_lvl() != 0);
        }

        Schedule* schedule = new Schedule(leauge);
        for (int i = 0; i < TEAMS_SIZE; i++)
        {
            assert((*leauge)[i] == (*schedule->get_leauge())[i]);
        }
        assert(schedule->get_games_counter() == 380);
        cout << "There where " << schedule->get_games_counter() << " games\n";
        Score* score = new Score(leauge, schedule);

        for (auto i = leauge->begin(); i != leauge->end(); ++i)
        {
            std::cout << *i << '\n';
        }
        
        
    }// Init check

    // SUBCASE(""){}
}
