// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 BBQCoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        (     1, uint256("0x65a7f2baaefd3e45d6f355fee028d0e1012b9639bfaf21d8db4ee81a86df41aa"))
        (     8, uint256("0x8614eae7441737fa1c862713ecce5a7251136931887d6767f02ca439961a9b5a"))
        (    32, uint256("0x19ed170b3ecbb228ee085869ed8afdaf1ade6e57045b03d9e0a05c8c7e3b5f75"))
<<<<<<< HEAD
        (100000, uint256("0x4ed87fd1d6d62608cd2f87899cd2489c1296013cf30af3d2beac3e060e57d6bd"))
        (200000, uint256("0x6f694594a1a0185807742e0c24f8c535d082fa6e5eebf358825be10349de80ed"))
        (300000, uint256("0xd8eb4bfc48c622e6e18ddb8ec24a784d220afa31c19eadf4b9acbd3cc2869f64"))
        (363628, uint256("0xf8359e909751dbe88fa3824378602c4bb24b36da3d24f940b4c27eab4f4fa3bb"))
=======
        (   674, uint256("0xd70cd046b76ab8bd9af9953fa56d852f6a671a1f009322c63b096071723ec8d4"))
        ( 86425, uint256("0x5bb676c3ea2d9cdc2589e7fa53874c425317aa9dadf0ae503fb7cf804cab9762"))
        (303403, uint256("0x6d7493ffc82a9553cf20ffca41ace762c3e4e7db4fe6f820675cdf387116342f"))
        (350000, uint256("0xd637294e567884acc789daa2aa12705d918a9545fd96ea6088e979df858fac31"))
>>>>>>> 7fc723d451755a4bb18337546653d88a385f7f43
        ;
/*
    static MapCheckpoints mapCheckpointsTestnet =
        boost::assign::map_list_of
        ( 546, uint256("000000002a936ca763904c3c35fce2f3556c559c0214345d31b1bcebf76acb70"))
        ;
*/
    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;

        return mapCheckpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}
