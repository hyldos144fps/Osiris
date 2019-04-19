#pragma once

#include "NetworkChannel.h"
#include "Utils.h"
#include "Vector.h"

struct PlayerInfo {
    __int64 pad;
    union {
        __int64 steamID64;
        __int32 xuidLow;
        __int32 xuidHigh;
    };
    char name[128];
    int userId;
    char steamIdString[20];
    char pad1[16];
    unsigned long steamId;
    char friendsName[128];
    bool fakeplayer;
    bool ishltv;
    unsigned int customfiles[4];
    unsigned char filesdownloaded;
};

class Engine {
public:
    constexpr auto getPlayerInfo(int entityIndex, const PlayerInfo& playerInfo) noexcept
    {
        return callVirtualFunction<bool, void*, int, const PlayerInfo&>(this, 8)(this, entityIndex, playerInfo);
    }

    constexpr auto getLocalPlayer() noexcept
    {
        return callVirtualFunction<int, void*>(this, 12)(this);
    }

    constexpr auto getViewAngles(Vector& angles) noexcept
    {
        callVirtualFunction<void, void*, Vector&>(this, 18)(this, angles);
    }

    constexpr auto setViewAngles(const Vector& angles) noexcept
    {
        callVirtualFunction<void, void*, const Vector&>(this, 19)(this, angles);
    }

	constexpr auto getMaxClients() noexcept
	{
		return callVirtualFunction<int, void*>(this, 20)(this);
	}

	constexpr auto isInGame() noexcept
	{
		return callVirtualFunction<bool, void*>(this, 26)(this);
	}

    using Matrix = float[4][4];

    constexpr const Matrix& worldToScreenMatrix() noexcept
    {
        return callVirtualFunction<const Matrix&, void*>(this, 37)(this);
    }

    constexpr auto getNetworkChannel() noexcept
    {
        return callVirtualFunction<NetworkChannel*, void*>(this, 78)(this);
    }
};
