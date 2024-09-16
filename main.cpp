#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <sys/limits.h>
#include <sys/mman.h>
#include <curl/curl.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include "Iconcpp.h"
#include "ImguiPP.h"
#include "Menu.h"
#include "config.h"
#include "Icon.h"
#include "StrEnc.h"
#include "Font.h"
#include "Spoof.h"
#include "Tools.h"
#include "SDK.hpp"
#include "MemoryTools.h"
#include "obfuscate.h"
#include "Dobby/dobby.h"
#include "imgui/imgui.h"
#include "Helper/Includes.h"
#include "Helper/plthook.h"
#include "Helper/json.hpp"
#include "Helper/Items.h"
#include "base64/base64.h"
#include "Helper/fake_dlfcn.h".
#include "KittyMemory/MemoryPatch.h"
#include "imgui/backends/imgui_impl_android.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include "Vector3.hpp"
#include "Includes/Logger.h"
#include "Includes/Utils.h"
#include "Includes/Macros.h"
#include <xhook/xhook.h>
#include "sound.h"
#include "Image.hpp"
#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <thread>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>

#include <string>
#include <ctime>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/fcntl.h>

#include <android/log.h>
#include <cstdlib>

#include <mutex>
std::mutex mtx; 

#include "Colors.h"
ImFont* DX4Font;
// Log tag
#define TAG "AIDE"

float accent_color[4] = { 0.300f, 0.220f, 0.750f, 1.000f };
#define SLEEP_TIME 1000LL / 120LL
using json = nlohmann::json;
using namespace SDK;
bool initImGui = false;
bool killmessage = false;
bool nolagflasg = false;
bool ipadview = false;
bool isSpawnON  = false;
bool CROZN_XDD;
bool Bypass = true;
bool RadarCheto = true;
static int dark = 1;
float FOVSize = 150;
float density = -1;
json items_data;
time_t rng = 0;
std::string expiretime = "";
static std::string EXP = " ";
std::string g_Token, g_Auth;
bool bValid = false;
bool HIDEESP = true;
bool End = true;
bool PARACHUTE;
bool lolo = false;
bool check;
bool bear;
bool logined = false;

bool AllEsp;
bool AllAim;
uintptr_t AntsVoice;
uintptr_t anogs;
uintptr_t UE4;
uintptr_t anort;
uintptr_t TBlueData;
uintptr_t CrashSight;
uintptr_t gcloudcore;
uintptr_t gcloud;
    
uintptr_t AimBullet_Offset;
uintptr_t GWorld_Offset, GUObjectArray_Offset, SilentAim_Offset;
ImColor outlinecolor = IM_COL32(0, 0, 0, 255);

char extra[32];
bool WriteAddr(void *addr, void *buffer, size_t length) {
    unsigned long page_size = sysconf(_SC_PAGESIZE);
    unsigned long size = page_size * sizeof(uintptr_t);
    return mprotect((void *) ((uintptr_t) addr - ((uintptr_t) addr % page_size) - page_size), (size_t) size, PROT_EXEC | PROT_READ | PROT_WRITE) == 0 && memcpy(addr, buffer, length) != 0;
}



#define DefineHook(RET, NAME, ARGS) \
	RET(*Orig_##NAME)               \
	ARGS;                           \
	RET Hook_##NAME ARGS

template<typename T>
void Write(uintptr_t addr, T value) {
    WriteAddr((void *) addr, &value, sizeof(T));
}

int screenWidth = -1, glWidth, screenHeight = -1, glHeight;


//@DX4_CHEATS

enum EAimMode {
    AimBullet = 0,
    Pbullet = 1,
    AimBot = 2
};

enum EAimTarget {
    Chest = 0,
    Head = 1

};


enum EAimBy {
    FOV = 0,
    Distance = 1
};

enum EAimTrigger {
    Shooting = 0,
    None = 1,
    Scoping = 2,
    Both = 3,
    Any = 4
};

std::map<int, bool> Items;
std::map<int, float *> ItemColors;

struct sConfig {
	    bool V1;
    bool V2;
    bool V3;
    bool V4;
    bool V5;
    bool V6;
	bool V7;
	
    struct sESPMenu {
     
        bool Line;
        bool AutoFire;
        bool Box;
        bool Skeleton;
        bool Name;
        bool Distance;
        bool TeamID;
        bool NoBot;
		bool Box3D;
		bool Vehicle;
		bool Health;
		bool GrenadeWarn;
        bool info;
		bool LootBox;
    };
    sESPMenu ESPMenu;


    struct sHighRisk {
        bool NoShake;
        bool NoRecoil;
        bool InstantHit;
        bool kill;
        bool God;
        bool Down;
        bool UP;
        bool RIGHT;
        bool LEFT;
        bool FRONT;
        bool BACK;
        bool Ipad;
        bool NoFog;
        float Skill = 4;
        float Sland = 15000;
        float sinstanthit = 100000;
    };
    sHighRisk HighRisk{0};
    struct sVehicleESP {
        bool ShowVehicle;
        bool ShowDistance;
    };
    sVehicleESP VehicleESP{0};
    struct sWeaponAim {
        float Cross;
        float Recc;
        bool Enable;
        EAimTarget Target;
        EAimTrigger Trigger;
        bool IgnoreKnocked;
        bool VisCheck;
        bool IgnoreBot;
		bool Bot;
        
    };
        struct sAimMenu {
        bool Enable;
        bool AimBot;
        EAimMode Mode;
        EAimBy AimBy;
        EAimTarget Target;
        EAimTrigger Trigger;
        bool RecoilComparison;
        float Recc;
        float Line;
        bool Prediction;
        float Cross;
        float Crosss;
        bool IgnoreKnocked;
        bool VisCheck;
        bool IgnoreBot;
        float Meter;
    };
    sAimMenu SilentAim{0};
    sAimMenu AimBot{0};

    struct sColorsESP {
        float *Line;
        float *Box;
        float *Name;
        float *Distance;
        float *Skeleton;
        float *Vehicle;
		float *Fov;
    };
    sColorsESP ColorsESP{0};
    struct sOTHER {
        bool FPS;
        bool HIDEESP;
    };
    sOTHER OTHER{0};
};
sConfig Config{0};

#define CREATE_COLOR(r, g, b, a) new float[4] {(float)r, (float)g, (float)b, (float)a};

// @DX4_CHEATS
void fuck(void *offset, void* ptr, void **orig)
{
#if defined(__aarch64__)
    A64HookFunction(offset, ptr, orig);
#else
    MSHookFunction(offset, ptr, orig);
#endif
}

uintptr_t GetLibMapFileSize(const char *libraryName) {
    if(strstr(libraryName, "anon:libc_malloc"))
    return 0;
    FILE *fp = fopen("/proc/self/maps", "rt");
    uintptr_t baseAddress = 0;
    if (fp != NULL) {
        char line[512] = {0};
        while (fgets(line, sizeof(line), fp)) {
            if (strstr(line, libraryName)) {
                uintptr_t startAddr, endAddr;
                sscanf(line, "%lx-%lx", &startAddr, &endAddr);
                baseAddress = endAddr - startAddr;
                break;
            }
        }
       fclose(fp);
    }
 return baseAddress;
}


android_app *g_App = 0;
ASTExtraPlayerCharacter *g_LocalPlayer = 0;
ASTExtraPlayerController *g_LocalController = 0;


#define GNames_Offset 0x6d2e350
#define GUObject_Offset 0xc27e7f0
#define GetActorArray 0x8956ea4
#define GNativeAndroidApp_Offset 0xbde0f88
#define Actors_Offset 0xa0
#define SwapBuffers 0xA7CD730


struct sRegion {
    uintptr_t start, end;
};

std::vector<sRegion> trapRegions;

bool isObjectInvalid(UObject *obj) {
    if (!Tools::IsPtrValid(obj)) {
        return true;
    }

    if (!Tools::IsPtrValid(obj->ClassPrivate)) {
        return true;
    }

    if (obj->InternalIndex <= 0) {
        return true;
    }

    if (obj->NamePrivate.ComparisonIndex <= 0) {
        return true;
    }

    if ((uintptr_t)(obj) % sizeof(uintptr_t) != 0x0 && (uintptr_t)(obj) % sizeof(uintptr_t) != 0x4) {
        return true;
    }

    if (std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) { return ((uintptr_t) obj) >= region.start && ((uintptr_t) obj) <= region.end; }) ||
        std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) { return ((uintptr_t) obj->ClassPrivate) >= region.start && ((uintptr_t) obj->ClassPrivate) <= region.end; })) {
        return true;
    }

    return false;
}
/*
UWorld *GetWorld() {
    auto GEngine = *(UEngine **) (g_UE4 + GEngine_Offset);
    if (GEngine) {
        auto ViewPort = GEngine->GameViewport;
        if (ViewPort) {
            return ViewPort->World;
        }
    }
    return 0;
}
*/
static UEngine *GEngine = 0;
UWorld *GetWorld() {
    while (!GEngine) {
        GEngine = UObject::FindObject<UEngine>("UAEGameEngine Transient.UAEGameEngine_1");
        sleep(1);
    }
    if (GEngine) {
        auto ViewPort = GEngine->GameViewport;
        if (ViewPort) {
            return ViewPort->World;
        }
    }
    return 0;
}

TNameEntryArray *GetGNames() {
    return ((TNameEntryArray *(*)()) (UE4 + GNames_Offset))();
}

std::vector<AActor *> getActors() {
    auto World = GetWorld();
    if (!World)
        return std::vector<AActor *>();
 
    auto PersistentLevel = World->PersistentLevel;
    if (!PersistentLevel)
        return std::vector<AActor *>();
 
    struct GovnoArray {
        uintptr_t base;
        int32_t count;
        int32_t max;
    };
    static thread_local GovnoArray Actors{};
 
    Actors = *(((GovnoArray*(*)(uintptr_t))(UE4 + GetActorArray))(reinterpret_cast<uintptr_t>(PersistentLevel)));
 
    if (Actors.count <= 0) {
        return {};
    }
 
    std::vector<AActor *> actors;
    for (int i = 0; i < Actors.count; i++) {
        auto Actor = *(uintptr_t *) (Actors.base + (i * sizeof(uintptr_t)));
        if (Actor) {
            actors.push_back(reinterpret_cast<AActor *const>(Actor));
        }
    }
    return actors;
}


std::string deviceBrandModel() {
    if (!g_App)
        return "";

    auto activity = g_App->activity;
    if (!activity)
        return "";

    auto vm = activity->vm;
    if (!vm)
        return "";

    auto object = activity->clazz;
    if (!object)
        return "";

    std::string result;

    JNIEnv *env;
    vm->AttachCurrentThread(&env, 0);
    
        std::string b = Tools::GetDeviceBrand(env);
        b += " - ";
        b += Tools::GetDeviceModel(env);
    
    vm->DetachCurrentThread();

    return b;
}





std::string getObjectPath(UObject *Object) {
    std::string s;
    for (auto super = Object->ClassPrivate; super; super = (UClass *) super->SuperStruct) {
        if (!s.empty())
            s += ".";
        s += super->NamePrivate.GetName();
    }
    return s;
}


//@DX4_CHEATS
int32_t ToColor(float *col) {
    return ImGui::ColorConvertFloat4ToU32(*(ImVec4 *) (col));
}

void DrawText(ImDrawList *draw, const std::string &text, const FVector2D &position, ImU32 color, float fontSize)
{
    draw->AddText(NULL, fontSize, {position.X, position.Y}, color, text.c_str());
}

void DrawTextWithBorder(ImDrawList *draw, const std::string &text, const FVector2D &position, ImU32 textColor, ImU32 borderColor, float fontSize)
{
    float borderSize = 1.0f;

    for (int x = -1; x <= 1; ++x)
    {
        for (int y = -1; y <= 1; ++y)
        {
            if (x == 0 && y == 0)
                continue;

            DrawText(draw, text, {position.X + x * borderSize, position.Y + y * borderSize}, borderColor, fontSize);
        }
    }
    DrawText(draw, text, position, textColor, fontSize);
}



FRotator ToRotator(FVector local, FVector target) {
    FVector rotation = UKismetMathLibrary::Subtract_VectorVector(local, target);
    float hyp = sqrt(rotation.X * rotation.X + rotation.Y * rotation.Y);
    FRotator newViewAngle = {0};
    newViewAngle.Pitch = -atan(rotation.Z / hyp) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Yaw = atan(rotation.Y / rotation.X) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Roll = (float) 0.f;
    if (rotation.X >= 0.f)
        newViewAngle.Yaw += 180.0f;
    return newViewAngle;
}


                    auto protect(uintptr_t addr, size_t len, int32_t prot) {
     static_assert(PAGE_SIZE == 4096);
     constexpr size_t page_size =                static_cast<size_t>(PAGE_SIZE);
    void* start = reinterpret_cast<void*>(addr & -page_size);
    uintptr_t end = (addr + len + page_size - 1) & -page_size;
    return mprotect(start, end - reinterpret_cast<uintptr_t>(start), prot);
}

FVector WorldToRadar(float Yaw, FVector Origin, FVector LocalOrigin, float PosX, float PosY, Vector3 Size, bool &outbuff) {
    bool flag = false;
    double num = (double)Yaw;
    double num2 = num * 0.017453292519943295;
    float num3 = (float)std::cos(num2);
    float num4 = (float)std::sin(num2);
    float num5 = Origin.X - LocalOrigin.X;
    float num6 = Origin.Y - LocalOrigin.Y;
    struct FVector Xector;
    Xector.X = (num6 * num3 - num5 * num4) / 150.f;
    Xector.Y = (num5 * num3 + num6 * num4) / 150.f;
    struct FVector Xector2;
    Xector2.X = Xector.X + PosX + Size.X / 2.f;
    Xector2.Y = -Xector.Y + PosY + Size.Y / 2.f;
    bool flag2 = Xector2.X > PosX + Size.X;
    if (flag2) {
        Xector2.X = PosX + Size.X;
    }else{
        bool flag3 = Xector2.X < PosX;
        if (flag3) {
            Xector2.X = PosX;
        }
    }
    bool flag4 = Xector2.Y > PosY + Size.Y;
    if (flag4) {
        Xector2.Y = PosY + Size.Y;
    }else{
        bool flag5 = Xector2.Y < PosY;
        if (flag5){
            Xector2.Y = PosY;
        }
    }
    bool flag6 = Xector2.Y == PosY || Xector2.X == PosX;
    if (flag6){
        flag = true;
    }
    outbuff = flag;
    return Xector2;
}

// ======================================================================== //

#define W2S(w, s) UGameplayStatics::ProjectWorldToScreen(localController, w, true, s)

static char path[200];
static int currentItem = 0;

FVector operator*(const FVector &vector, float scalar)
{
    return FVector({vector.X * scalar, vector.Y * scalar, vector.Z * scalar});
}

int32_t (*orig_ANativeWindow_getWidth)(ANativeWindow *window);
int32_t _ANativeWindow_getWidth(ANativeWindow *window)
{
    screenWidth = orig_ANativeWindow_getWidth(window);
    return orig_ANativeWindow_getWidth(window);
}

void (*orig_onInputEvent)(void *thiz, void *ex_ab, void *ex_ac);
void onInputEvent(void *thiz, void *ex_ab, void *ex_ac)
{
    orig_onInputEvent(thiz, ex_ab, ex_ac);
    if (initImGui)
    {
        ImGui_ImplAndroid_HandleInputEvent((AInputEvent *)thiz, {(float)screenWidth / (float)glWidth, (float)screenHeight / (float)glHeight});
    }
    return;
}

int32_t (*orig_ANativeWindow_getHeight)(ANativeWindow *window);
int32_t _ANativeWindow_getHeight(ANativeWindow *window)
{
    screenHeight = orig_ANativeWindow_getHeight(window);
    return orig_ANativeWindow_getHeight(window);
}


bool isInsideFOVs(int x, int y) {
    if (!FOVSize)
        return true;

    int circle_x = glWidth / 2;
    int circle_y = glHeight / 2;
    int rad = FOVSize;
    return (x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad;
}

auto GetTargetForAimBot() {
   ASTExtraPlayerCharacter *result = 0;
    float max = std::numeric_limits<float>::infinity();
    auto Actors = getActors();
    auto localPlayer = g_LocalPlayer;
    auto localController = g_LocalController;
    if (localPlayer)
    {
        for (auto Actor : Actors)
        {
            if (isObjectInvalid(Actor))
                continue;
            if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass()))
            {
                auto Player = (ASTExtraPlayerCharacter *)Actor;
                auto Target = (ASTExtraPlayerCharacter *) Actor;
                
                float dist = localPlayer->GetDistanceTo(Target) / 100.0f;

                if (dist > Config.AimBot.Meter)
					continue;
                
                if (Player->PlayerKey == localPlayer->PlayerKey)
                    continue;
                if (Player->TeamID == localPlayer->TeamID)
                    continue;
                if (Player->bDead)
                    continue;
                    
                    
                              if (Config.AimBot.IgnoreKnocked) {
                            if (Player->Health == 0.0f)
                                continue;
                        }


                        if (Config.AimBot.VisCheck) {
                            if (!localController->LineOfSightTo(Player, {0, 0, 0}, true))
                                continue;
                        }
                        if (Config.AimBot.IgnoreBot) {
                            if (Player->bEnsure)
                                continue;
                        }

                        auto Root = Player->GetBonePos("Root", {});
                auto Head = Player->GetBonePos("Head", {});
                FVector2D RootSc, HeadSc;
                if (W2S(Root, &RootSc) && W2S(Head, &HeadSc))
                {
                    float height = abs(HeadSc.Y - RootSc.Y);
                    float width = height * 0.65f;

                    FVector middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};
                    if ((middlePoint.X >= 0 && middlePoint.X <= glWidth) && (middlePoint.Y >= 0 && middlePoint.Y <= glHeight))
                    {
                        FVector2D v2Middle = FVector2D((float)(glWidth / 2), (float)(glHeight / 2));
                        FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);
                        
                        
                                if(isInsideFOVs((int)middlePoint.X, (int)middlePoint.Y)) {

                                float dist = FVector2D::Distance(v2Middle, v2Loc);

                                if (dist < max) {
                            max = dist;
                            result = Player;
                                }
                              }
                            }
                        }
                    
                
            }
        }
    }

    return result;
}

auto GetTargetByPussy() {
    ASTExtraPlayerCharacter *result = 0;
    float max = std::numeric_limits<float>::infinity();

    auto GWorld = GetWorld();
    if (GWorld) {
        ULevel *PersistentLevel = GWorld->PersistentLevel;
        if (PersistentLevel) {
            TArray<AActor *> Actors = *(TArray<AActor *> *) ((uintptr_t) PersistentLevel +
                                                             Actors_Offset);


            auto localPlayer = g_LocalPlayer;
            auto localController = g_LocalController;

            if (localPlayer) {
                for (int i = 0; i < Actors.Num(); i++) {
                    auto Actor = Actors[i];
                    if (isObjectInvalid(Actor))
                        continue;

            if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                auto Player = (ASTExtraPlayerCharacter *) Actor;

                if (Player->PlayerKey == localPlayer->PlayerKey)
                    continue;

                if (Player->TeamID == localPlayer->TeamID)
                    continue;

                if (Player->bDead)
                    continue;

                if (Config.SilentAim.IgnoreKnocked) {
                    if (Player->Health == 0.0f)
                        continue;
                }
        
                if (Config.SilentAim.IgnoreBot) {
                    if (Player->bEnsure)
                        continue;
                }
                  
                 
                    if (!localController->LineOfSightTo(Player, {0, 0, 0}, true))
                              continue;
      
                        float dist = g_LocalPlayer->GetDistanceTo(Player);
                             if (dist < max) {
                                 max = dist;
                              result = Player;
                        
                              }
                            }
                        }
                    }
                }
            }
        

    return result;
}


auto GetTargetByCrossDist() {
    ASTExtraPlayerCharacter *result = 0;
    float max = std::numeric_limits<float>::infinity();

    auto Actors = getActors();

    auto localPlayer = g_LocalPlayer;
    auto localController = g_LocalController;

    if (localPlayer) {
        for (int i = 0; i < Actors.size(); i++) {
            auto Actor = Actors[i];
            if (isObjectInvalid(Actor))
                continue;

            if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                auto Player = (ASTExtraPlayerCharacter *) Actor;

                if (Player->PlayerKey == localPlayer->PlayerKey)
                    continue;

                if (Player->TeamID == localPlayer->TeamID)
                    continue;

                if (Player->bDead)
                    continue;

                if (Config.SilentAim.IgnoreKnocked) {
                    if (Player->Health == 0.0f)
                        continue;
                }

                if (Config.SilentAim.VisCheck) {
                    if (!localController->LineOfSightTo(Player, {0, 0, 0}, true))
                        continue;
                }
                if (Config.SilentAim.IgnoreBot) {
                    if (Player->bEnsure)
                        continue;
                }

                auto Root = Player->GetBonePos("Root", {});
                auto Head = Player->GetBonePos("Head", {});

                FVector2D RootSc, HeadSc;
                if (W2S(Root, &RootSc) && W2S(Head, &HeadSc)) {
                    float height = abs(HeadSc.Y - RootSc.Y);
                    float width = height * 0.65f;

                    FVector middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};
                    if ((middlePoint.X >= 0 && middlePoint.X <= glWidth) && (middlePoint.Y >= 0 && middlePoint.Y <= glHeight)) {
                        FVector2D v2Middle = FVector2D((float) (glWidth / 2), (float) (glHeight / 2));
                        FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);

                        float dist = FVector2D::Distance(v2Middle, v2Loc);

                        if (dist < max) {
                            max = dist;
                            result = Player;
                        }
                    }
                }
            }
        }
    }

    return result;
}


ASTExtraPlayerCharacter *GetTargetForAim() {
    if (Config.AimBot.AimBy == EAimBy::FOV) {
        return GetTargetByCrossDist();
    }

    return 0;
}


//@DX4_CHEATS

const char *GetVehicleName(ASTExtraVehicleBase *Vehicle) {
    switch (Vehicle->VehicleShapeType) {
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike_SideCart:
            return "Motorbike";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Dacia:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyDacia:
            return "Dacia";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_MiniBus:
            return "Mini Bus";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PickUp:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PickUp01:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyPickup:
            return "Pick Up";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Buggy:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyBuggy:
            return "Buggy";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ01:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ02:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ03:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyUAZ:
            return "UAZ";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PG117:
            return "PG117";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Aquarail:
            return "Aquarail";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Mirado:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Mirado01:
            return "Mirado";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Rony:
            return "Rony";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Scooter:
            return "Scooter";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_SnowMobile:
            return "Snow Mobile";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_TukTukTuk:
            return "Tuk Tuk";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_SnowBike:
            return "Snow Bike";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Surfboard:
            return "Surf Board";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Snowboard:
            return "Snow Board";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Amphibious:
            return "Amphibious";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_LadaNiva:
            return "Lada Niva";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAV:
            return "UAV";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_MegaDrop:
            return "Mega Drop";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini01:
            return "Lamborghini";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_GoldMirado:
            return "Gold Mirado";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_BigFoot:
            return "Big Foot";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyUH60:
            return "UH60";
            break;
        default:
            return "Vehicle";
            break;
    }
    return "Vehicle";
}

void Box4Line(ImDrawList *draw, float thicc, int x, int y, int w, int h, int color) {
    int iw = w / 4;
    int ih = h / 4;
    // top
    draw->AddRect(ImVec2(x, y),ImVec2(x + iw, y), color, thicc);
    draw->AddRect(ImVec2(x + w - iw, y),ImVec2(x + w, y), color, thicc);
    draw->AddRect(ImVec2(x, y),ImVec2(x, y + ih), color, thicc);
    draw->AddRect(ImVec2(x + w - 1, y),ImVec2(x + w - 1, y + ih), color, thicc);;
    // bottom
    draw->AddRect(ImVec2(x, y + h),ImVec2(x + iw, y + h), color, thicc);
    draw->AddRect(ImVec2(x + w - iw, y + h),ImVec2(x + w, y + h), color, thicc);
    draw->AddRect(ImVec2(x, y + h - ih), ImVec2(x, y + h), color, thicc);
    draw->AddRect(ImVec2(x + w - 1, y + h - ih), ImVec2(x + w - 1, y + h), color, thicc);
}
    

void (*orig_shoot_event)(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, void *unk1, int unk2) = 0;

bool qwcifqvs86y8fify = false;

void shoot_event(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, ASTExtraShootWeapon *weapon, int unk1) {
if (qwcifqvs86y8fify) {
  qwcifqvs86y8fify = false;
  g_LocalController->bIsPressingFireBtn = false;
thiz->OwnerShootWeapon->StopFire(EFreshWeaponStateType::FreshWeaponStateType_Idle);
}





        if (Config.SilentAim.Enable) {
        ASTExtraPlayerCharacter *Target = GetTargetByCrossDist();
        if (Target) {
            bool triggerOk = false;
            if (Config.SilentAim.Trigger != EAimTrigger::None) {
                if (Config.SilentAim.Trigger == EAimTrigger::Shooting) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring;
                } else if (Config.SilentAim.Trigger == EAimTrigger::Scoping) {
                    triggerOk = g_LocalPlayer->bIsGunADS;
                } else if (Config.SilentAim.Trigger == EAimTrigger::Both) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring && g_LocalPlayer->bIsGunADS;
                } else if (Config.SilentAim.Trigger == EAimTrigger::Any) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring || g_LocalPlayer->bIsGunADS;
                }
            } else triggerOk = true;
            if (triggerOk) {
                FVector targetAimPos = Target->GetBonePos("Head", {});
                if (Config.SilentAim.Target == EAimTarget::Chest) {
                    targetAimPos.Z -= 25.0f;
                }
                
                
                UShootWeaponEntity *ShootWeaponEntityComponent = thiz->ShootWeaponEntityComponent;

                
            
                if (ShootWeaponEntityComponent) {
                    ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                    if (CurrentVehicle) {
                        FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;

                        float dist = g_LocalPlayer->GetDistanceTo(Target);
                        auto timeToTravel = dist / ShootWeaponEntityComponent->BulletFireSpeed;

                        targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(LinearVelocity, timeToTravel));
                    } else {
                        FVector Velocity = Target->GetVelocity();

                        float dist = g_LocalPlayer->GetDistanceTo(Target);
                        auto timeToTravel = dist / ShootWeaponEntityComponent->BulletFireSpeed;

                        targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(Velocity, timeToTravel));
                    }
                    rot = ToRotator(g_LocalController->PlayerCameraManager->CameraCache.POV.Location, targetAimPos);
                                                       
                                        
                                    
                                }
                            }
                        }
                    }
return orig_shoot_event(thiz, start, rot, weapon, unk1);
}


	

     

class FPSCounter {
protected:
    unsigned int m_fps;
    unsigned int m_fpscount;
    long m_fpsinterval;

public:
    FPSCounter() : m_fps(0), m_fpscount(0), m_fpsinterval(0) {
    }

    void update() {
        m_fpscount++;

        if (m_fpsinterval < time(0)) {
            m_fps = m_fpscount;

            m_fpscount = 0;
            m_fpsinterval = time(0) + 1;
        }
    }

    unsigned int get() const {
        return m_fps;
    }
};

FPSCounter fps;

void DrawBoxEnemy(ImDrawList *draw, ImVec2 X, ImVec2 Y, float thicc, int color) {
    draw->AddLine({X.x, X.y}, {Y.x, Y.y}, color, thicc);
}

int DX4_CHEATS_FLOAT(long int addr, float value){
    Tools::WriteAddr((void*)(addr), (void*)&value , 4);
    return 0;
}

int DX4_CHEATS_QWORD(long int addr, int64_t value){
    Tools::WriteAddr((void*)(addr),(void*)&value ,sizeof(value));
    return 0;
}


//@DX4_CHEATS




void DrawESP(ImDrawList *draw, int screenWidth, int screenHeight) {
    
    if (!g_Token.empty() && !g_Auth.empty() && g_Token == g_Auth) {
         
draw->AddText({((float) density / 20.0f), 50}, IM_COL32(255, 255, 255, 255), OBFUSCATE("Package Name -> com.pubg.imobile"));

        std::string b = deviceBrandModel();
draw->AddText({((float) density / 20.0f), 70}, IM_COL32(255, 255, 255, 255), b.c_str());
        
       if (Bypass) { ////auto bypass run
      
//paste bypass here

}
	
	
	
    auto GWorld = GetWorld();
    if (GWorld) {
        if (GWorld->PersistentLevel) {
            auto Actors = *(TArray<AActor *> *) ((uintptr_t) GWorld->PersistentLevel + Actors_Offset);

            int totalEnemies = 0, totalBots = 0;
            
            ASTExtraPlayerCharacter *localPlayer = 0;
            ASTExtraPlayerController *localController = 0;
            
				for (int i = 0; i < Actors.Num(); i++) {
                auto Actor = Actors[i];
                if (isObjectInvalid(Actor))
                    continue;

                if (Actor->IsA(ASTExtraPlayerController::StaticClass())) {
                    localController = (ASTExtraPlayerController *) Actor;
                    break;
                }
            }
		
			
            if (localController) {
                for (int i = 0; i < Actors.Num(); i++) {
                    auto Actor = Actors[i];
                    if (isObjectInvalid(Actor))
                        continue;

                    if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                        if (((ASTExtraPlayerCharacter *) Actor)->PlayerKey == localController->PlayerKey) {
                            localPlayer = (ASTExtraPlayerCharacter *) Actor;
                            break;
                        }
                    }
                }


            if (localPlayer) {
                    if (localPlayer->PartHitComponent) {
                        auto ConfigCollisionDistSqAngles = localPlayer->PartHitComponent->ConfigCollisionDistSqAngles;
                        for (int j = 0; j < ConfigCollisionDistSqAngles.Num(); j++) {
                            ConfigCollisionDistSqAngles[j].Angle = 90.0f;
                        }
                        localPlayer->PartHitComponent->ConfigCollisionDistSqAngles = ConfigCollisionDistSqAngles;
                    }
                    
                    
                       if (Config.HighRisk.NoRecoil || Config.HighRisk.NoShake || Config.HighRisk.InstantHit  || Config.HighRisk.kill) {
                    auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                    if (WeaponManagerComponent) {
                        auto Slot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                        if ((int) Slot.GetValue() >= 1 && (int) Slot.GetValue() <= 3) {
                            auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
                            if (CurrentWeaponReplicated) {
                                auto ShootWeaponEntityComp = CurrentWeaponReplicated->ShootWeaponEntityComp;
                                auto ShootWeaponEffectComp = CurrentWeaponReplicated->ShootWeaponEffectComp;
                                if (ShootWeaponEntityComp && ShootWeaponEffectComp) {

                                    if (Config.HighRisk.NoRecoil) {
                                        memset(&ShootWeaponEntityComp->RecoilInfo, 0, sizeof(FSRecoilInfo));

                                        ShootWeaponEntityComp->AccessoriesVRecoilFactor = 0.0f;
                                        ShootWeaponEntityComp->AccessoriesHRecoilFactor = 0.0f;
                                        ShootWeaponEntityComp->AccessoriesRecoveryFactor = 0.0f;

                                        memset(&ShootWeaponEntityComp->DeviationInfo, 0, sizeof(FSDeviation));

                                        ShootWeaponEntityComp->ShotGunCenterPerc = 0.0f;
                                        ShootWeaponEntityComp->ShotGunVerticalSpread = 0.0f;
                                        ShootWeaponEntityComp->ShotGunHorizontalSpread = 0.0f;

                                        ShootWeaponEntityComp->GameDeviationFactor = 0.0f;
                                        ShootWeaponEntityComp->GameDeviationAccuracy = 0.0f;

                                        ShootWeaponEntityComp->RecoilKickADS = 0.0f;
                                    }

                                    if (Config.HighRisk.NoShake) {
                                        ShootWeaponEffectComp->CameraShakeInnerRadius = 0.0f;
                                        ShootWeaponEffectComp->CameraShakeOuterRadius = 0.0f;
                                        ShootWeaponEffectComp->CameraShakFalloff = 0.0f;
                                    }

                                    if (Config.HighRisk.kill) {
                                        ShootWeaponEntityComp->DamageImpulse = (float) Config.HighRisk.Skill;
                                        ShootWeaponEntityComp->ExtraHitPerformScale = (float) Config.HighRisk.Skill;
                                    }
                                }
                            }
                        }
                    }
                }
                    
                    
                    
                    
                    
                    static bool bShooting = false;
                             if (Config.SilentAim.Enable) {
                    auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                    if (WeaponManagerComponent) {
                        auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                        if ((int) propSlot.GetValue() >= 1 && (int) propSlot.GetValue() <= 3) {
                            auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
                            if (CurrentWeaponReplicated) {
                                auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                                
                                
                                if (ShootWeaponComponent) {
                                    
                                    
                                    
                                    
    int shoot_event_idx = 168; 
    
    
auto VTable = (void **) ShootWeaponComponent->VTable;

auto f_mprotect = [](uintptr_t addr, size_t len, int32_t prot) -> int32_t {
  static_assert(PAGE_SIZE == 4096);
  constexpr size_t page_size = static_cast<size_t>(PAGE_SIZE);
  void* start = reinterpret_cast<void*>(addr & -page_size);
  uintptr_t end = (addr + len + page_size - 1) & -page_size;
  
  return mprotect(start, end - reinterpret_cast<uintptr_t>(start), prot);
};

if (VTable) {
    uintptr_t table_entry = (uintptr_t)&VTable[shoot_event_idx];
    
    if (VTable[shoot_event_idx] != shoot_event) {
        orig_shoot_event = decltype(orig_shoot_event)(VTable[shoot_event_idx]);
        
        f_mprotect(table_entry, sizeof(uintptr_t), PROT_READ | PROT_WRITE);
        
        uintptr_t new_func_ptr = reinterpret_cast<uintptr_t>(&shoot_event);
        VTable[shoot_event_idx] = reinterpret_cast<void*>(new_func_ptr);
        
        f_mprotect(table_entry, sizeof(uintptr_t), PROT_READ | PROT_EXEC);
    }
}

}
}
}
}
}


                        
                        
    if (Config.ESPMenu.AutoFire) {
  if (GetTargetByPussy()) {
    localController->bIsPressingFireBtn = true;
    
  } else {
   
    qwcifqvs86y8fify = true;
    
  }
}
        
                        
                //Aimbot//
                if (Config.AimBot.Enable) {
                    ASTExtraPlayerCharacter *Target = GetTargetForAimBot();
                    if (Target) {
                        bool triggerOk = false;
                        if (Config.AimBot.Trigger != EAimTrigger::None) {
                            if (Config.AimBot.Trigger == EAimTrigger::Shooting) {
                                triggerOk = localPlayer->bIsWeaponFiring;
                            } else if (Config.AimBot.Trigger == EAimTrigger::Scoping) {
                                triggerOk = localPlayer->bIsGunADS;
                            } else if (Config.AimBot.Trigger == EAimTrigger::Both) {
                                triggerOk = localPlayer->bIsWeaponFiring && localPlayer->bIsGunADS;
                            } else if (Config.AimBot.Trigger == EAimTrigger::Any) {
                                triggerOk = localPlayer->bIsWeaponFiring || localPlayer->bIsGunADS;
                            }
                        } else triggerOk = true;
                        if (triggerOk) {
                            FVector targetAimPos = Target->GetBonePos("Head", {});
                            if (Config.AimBot.Target == EAimTarget::Chest) {
                                targetAimPos.Z -= 25.0f;
                            }

                            auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                            if (WeaponManagerComponent) {
                                auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                                if ((int) propSlot.GetValue() >= 1 &&
                                    (int) propSlot.GetValue() <= 3) {
                                    auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
                                    if (CurrentWeaponReplicated) {
                                        auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                                        if (ShootWeaponComponent) {
                                            UShootWeaponEntity *ShootWeaponEntityComponent = ShootWeaponComponent->ShootWeaponEntityComponent;
                                            if (ShootWeaponEntityComponent) {
                                                ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                                                if (CurrentVehicle) {
                                                    FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;

                                                    float dist = localPlayer->GetDistanceTo(Target);
                                                    auto timeToTravel = dist /
                                                                        ShootWeaponEntityComponent->BulletFireSpeed;

                                                    targetAimPos = UKismetMathLibrary::Add_VectorVector(
                                                            targetAimPos,
                                                            UKismetMathLibrary::Multiply_VectorFloat(
                                                                    LinearVelocity, timeToTravel));
                                                } else {
                                                    FVector Velocity = Target->GetVelocity();

                                                    float dist = localPlayer->GetDistanceTo(Target);
                                                    auto timeToTravel = dist /
                                                                        ShootWeaponEntityComponent->BulletFireSpeed;

                                                    targetAimPos = UKismetMathLibrary::Add_VectorVector(
                                                            targetAimPos,
                                                            UKismetMathLibrary::Multiply_VectorFloat(
                                                                    Velocity, timeToTravel));
                                                                    
                                                }
                                                
                                                    
                                                                               
                               
                                                localController->SetControlRotation(ToRotator(
                                                        localController->PlayerCameraManager->CameraCache.POV.Location,
                                                        targetAimPos), "");

                                               if (Config.AimBot.RecoilComparison) {
                                               if (g_LocalPlayer->bIsGunADS) {
                                               if (g_LocalPlayer->bIsWeaponFiring) {
                                               float dist = g_LocalPlayer->GetDistanceTo(Target) / 100.f;                                                                                 
                                               targetAimPos.Z -= dist * Config.AimBot.Recc;
                                               }
                                               }
                                               }                                       
localController->SetControlRotation(ToRotator(localController->PlayerCameraManager->CameraCache.POV.Location, targetAimPos), "");
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                  }
                  
             
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\


                  
             
                                                                            for (int i = 0; i < Actors.Num(); i++) {
                        auto Actor = Actors[i];
                        if (isObjectInvalid(Actor))
                            continue;
                         if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                            long PlayerBoxClrCf = IM_COL32(0, 255, 47, 255);
                            long PlayerBoxClrCf2 = IM_COL32(0, 255, 47, 25);
                            auto Player = (ASTExtraPlayerCharacter *) Actor;
                            if (!localController->LineOfSightTo(Player, {0, 0, 0}, true)) {
                                PlayerBoxClrCf = IM_COL32(255, 0, 0, 255);
                                PlayerBoxClrCf2 = IM_COL32(255, 0, 0, 25);
                            }
                            
                            bool IsVisible = localController->LineOfSightTo(Player, {0, 0, 0}, true);
                            long TextClr;
                            int SCOLOR;
                            int SCOLOR2;
                            int SCOLO;
                            int SCOLOR4;

                            if (IsVisible)
                            {
                            TextClr = IM_COL32(255, 255, 255, 255);
                            SCOLOR4 = IM_COL32(255, 255, 0, 255);
                            SCOLOR = IM_COL32(0, 255, 0, 255);
                            SCOLOR2 = IM_COL32(0, 255, 0, 25);
                            SCOLO = IM_COL32(255, 100, 0, 100);
                            }else{
                            TextClr = IM_COL32(255, 255, 255, 255);
                            SCOLOR4 = IM_COL32(255, 0, 0, 255);
                            SCOLOR = IM_COL32(255, 0, 0, 255);
                            SCOLOR2 = IM_COL32(255, 0, 0, 25);
                            SCOLO = IM_COL32(0, 0, 0, 100);
                            }
                            
                            float Distance = localPlayer->GetDistanceTo(Player) / 100.0f;
                            if (Distance > 500.0f)
                                continue;

                            if (Player->PlayerKey == localController->PlayerKey)
                                continue;

                            if (Player->TeamID == localController->TeamID)
                                continue;

                            if (Player->bDead)
                                continue;

      

                                                if (Player->bEnsure)
                        totalBots++;
                    else totalEnemies++;

                            if (Config.ESPMenu.NoBot)
                            if (Player->bEnsure)
                                continue;

								float magic_number = (Distance);
                    float mx = (glWidth / 4) / magic_number;

                    float healthLength = glWidth / 17;
                    if (healthLength < mx)
                        healthLength = mx;
								
                            auto HeadPos = Player->GetBonePos("Head", {});
                            HeadPos.Z = HeadPos.Z + 1.0f; //head se line ooper
                            ImVec2 headPosSC;

                            auto RootPos = Player->GetBonePos("Root", {});
                            ImVec2 RootPosSC;
                            if (W2S(HeadPos, (FVector2D *) &headPosSC) && W2S(RootPos, (FVector2D *) &RootPosSC)) {
                            FVector2D screen(glWidth, glHeight);
                            FVector2D location(RootPosSC.x, headPosSC.y);



                                                                      if (Config.ESPMenu.Line) {
                                                if (Player->bEnsure) {
                                draw->AddLine({(float) glWidth / 2, 75}, headPosSC,
                                                  PlayerBoxClrCf, 1.5f);
                            } else {
                                    draw->AddLine({(float) glWidth / 2, 75}, headPosSC,
                                                  PlayerBoxClrCf, 1.5f);
                                }
							}
								
								       
                                if (Config.ESPMenu.Box) {
                            
                                float boxHeight = abs(headPosSC.y - RootPosSC.y);
                                    float boxWidth = boxHeight * 0.65f;
                                    ImVec2 vStart = {headPosSC.x - (boxWidth / 2), headPosSC.y};
                                    ImVec2 vEnd = {vStart.x + boxWidth, vStart.y + boxHeight};

                                    draw->AddRect(vStart, vEnd, PlayerBoxClrCf, 1.5f, 240, 1.7f);
                                    draw->AddRectFilled(vStart, vEnd, PlayerBoxClrCf2, 1.5f, 240);
                                }

                                if (Config.ESPMenu.Skeleton) {
                                    
                                    float boxWidth = 7.f - Distance * 0.03;
                                                draw->AddCircle({headPosSC.x, headPosSC.y},
                                                                boxWidth,
                                                                 TextClr,
                                                                0, 3.0f);
                                    
                                    static std::vector<std::string> right_arm{"neck_01",
                                                                              "clavicle_r",
                                                                              "upperarm_r",
                                                                              "lowerarm_r",
                                                                              "hand_r", "item_r"};
                                    static std::vector<std::string> left_arm{"neck_01",
                                                                             "clavicle_l",
                                                                             "upperarm_l",
                                                                             "lowerarm_l",
                                                                             "hand_l", "item_l"};
                                    static std::vector<std::string> spine{"Head", "neck_01",
                                                                          "spine_03",
                                                                          "spine_02", "spine_01",
                                                                          "pelvis"};
                                    static std::vector<std::string> lower_right{"pelvis", "thigh_r",
                                                                                "calf_r", "foot_r"};
                                    static std::vector<std::string> lower_left{"pelvis", "thigh_l",
                                                                               "calf_l", "foot_l"};
                                    static std::vector<std::vector<std::string>> skeleton{right_arm,
                                                                                          left_arm,
                                                                                          spine,
                                                                                          lower_right,
                                                                                          lower_left};

                                    for (auto &boneStructure: skeleton) {
                                        std::string lastBone;
                                        for (std::string &currentBone: boneStructure) {
                                            if (!lastBone.empty()) {
                                                ImVec2 boneFrom, boneTo;
                                                if (W2S(Player->GetBonePos(lastBone.c_str(), {}),
                                                        (FVector2D *) &boneFrom) &&
                                                    W2S(Player->GetBonePos(currentBone.c_str(), {}),
                                                        (FVector2D *) &boneTo)) {
                                                    draw->AddLine(boneFrom, boneTo,
                                                                  PlayerBoxClrCf, 2.0f);
                                                }
                                            }
                                            lastBone = currentBone;
                                        }
                                    }
                                }

                                
                                    if (Config.AimBot.Mode == EAimMode::AimBot || Config.AimBot.Mode == EAimMode::AimBullet || Config.AimBot.Mode == EAimMode::Pbullet) {
            if (Config.AimBot.AimBy == EAimBy::FOV) {
                draw->AddCircle(ImVec2(glWidth / 2, glHeight / 2), FOVSize, IM_COL32(255, 255, 255, 0), 0, 0.7f);;
                }
                
            }                     
                                
           }
								
								  if (Config.ESPMenu.Health) {
                                 
                                           int CurHP = (int) std::max(0, std::min((int) Player->Health,
                                                                       (int) Player->HealthMax));
                                int MaxHP = (int) Player->HealthMax;

                                long HPColor = IM_COL32(0, 255, 47, 150);
                                long HPRectColor = IM_COL32(1, 1, 1, 255);

                                if (Player->Health == 0.0f && !Player->bDead) {
                                    HPColor = IM_COL32(255, 0, 0, 150);

                                    CurHP = Player->NearDeathBreath;
                                    if (Player->NearDeatchComponent) {
                                        MaxHP = Player->NearDeatchComponent->BreathMax;
                                    }
                                    }
                        

                                float boxWidth = density / 3.2f; // width
                                boxWidth -= std::min(((boxWidth / 2) / 500.0f) * Distance,
                                                     boxWidth / 2);
                                float boxHeight = boxWidth * 0.19f; // height


                                ImVec2 vStart = {headPosSC.x - (boxWidth / 2),
                                                 headPosSC.y - (boxHeight * 1.9f)}; //ooper neeche

                                ImVec2 vEndFilled = {vStart.x + (CurHP * boxWidth / MaxHP),
                                                     vStart.y + boxHeight};
                                ImVec2 vEndRect = {vStart.x + boxWidth, vStart.y + boxHeight};

                                draw->AddRectFilled(vStart, vEndFilled, HPColor, 0.0f, 240);
                                draw->AddRect(vStart, vEndRect, HPRectColor, 0.0f, 240);
                                }
                                if (RadarCheto) {
                            bool out = false;
                            static struct Vector3 Pos;
                            static struct Vector3 Size;
                            static ImVec2 radarPosition(Pos.X, Pos.Y);
                            Pos.X = glWidth / 4.490;
                            Pos.Y = glHeight / 150;
                            Size.X = 150;
                            Size.Y = 150;
                            float RadarCenterX = Pos.X + (Size.X / 2);
                            float RadarCenterY = Pos.Y + (Size.Y / 2);
                            ImColor LineColor = ImColor(255, 255, 255, 255);
                            ImColor PointColor = ImColor(255, 0, 0, 255);
                            float TransparentBoxSize = 100.0f;
                            ImColor BackgroundColor = ImColor(0, 0, 0, 75);
                            ImColor TransparentBoxColor = BackgroundColor;
                            draw->AddRectFilled(ImVec2(Pos.X - (TransparentBoxSize - Size.X) / 2, Pos.Y - (TransparentBoxSize - Size.Y) / 2), ImVec2(Pos.X + Size.X + (TransparentBoxSize - Size.X) / 2, Pos.Y + Size.Y + (TransparentBoxSize - Size.Y) / 2), TransparentBoxColor, 0.0f, 0);
                            draw->AddLine(ImVec2(Pos.X, Pos.Y), ImVec2(Pos.X + Size.X, Pos.Y), LineColor, 1.0f);
                            draw->AddLine(ImVec2(Pos.X, Pos.Y + Size.Y), ImVec2(Pos.X + Size.X, Pos.Y + Size.Y), LineColor, 1.0f);
                            draw->AddLine(ImVec2(Pos.X, Pos.Y), ImVec2(Pos.X, Pos.Y + Size.Y), LineColor, 1.0f);
                            draw->AddLine(ImVec2(Pos.X + Size.X, Pos.Y), ImVec2(Pos.X + Size.X, Pos.Y + Size.Y), LineColor, 1.0f);
                            draw->AddLine(ImVec2(RadarCenterX, Pos.Y), ImVec2(RadarCenterX, Pos.Y + Size.Y), LineColor, 1.0f);
                            draw->AddLine(ImVec2(Pos.X, RadarCenterY), ImVec2(Pos.X + Size.X, RadarCenterY), LineColor, 1.0f);
                            draw->AddCircleFilled(ImVec2(RadarCenterX, RadarCenterY), 3.0f, LineColor, 1000);
                            FVector MyPosition = Player->RootComponent->RelativeLocation;
                            FVector EnemyPosition = localPlayer->RootComponent->RelativeLocation;
                            FVector single = WorldToRadar(localController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw, MyPosition, EnemyPosition, Pos.X, Pos.Y, Size, out);
                            if (Distance >= 0.0f && Distance < 500.0f) {
                            draw->AddCircleFilled(ImVec2(single.X, single.Y), 3, PlayerBoxClrCf);
                            }
                            }
								
								
                                      if (Config.ESPMenu.Name || Config.ESPMenu.Distance || Config.ESPMenu.Name) {
                                        //  DrawBoxEnemy(draw, ImVec2(headPosSC.x - healthLength, headPosSC.y - 28), ImVec2(headPosSC.x + healthLength, headPosSC.y - 28), 22, IM_COL32(153, 153, 255, 155));
                                    
                                    

                                    

                            if (Config.ESPMenu.Name) {
                            float boxHeight = abs(headPosSC.y - RootPosSC.y);
                                    float boxWidth = boxHeight * 0.65f;
                                 //   std::string s;
                                    
                                    float rectWidth = density / 2.0f;
                                rectWidth -= std::min(((rectWidth / 0.0f) / 0.0f) * Distance,
                                                     rectWidth / 0.0f);
                                float rectHeight = rectWidth * 2.0f;
                                
                                    ImVec2 vStart = {RootPosSC.x - (boxWidth / 0.65f),
                                                 RootPosSC.y - (boxHeight * 0.65f)};
                                 ImVec2 vEnd = {RootPosSC.x - (rectWidth / 3.7f),
                                                 RootPosSC.y - (rectHeight * 2.0f)};
                                    std::string s;
                                    std::string ws;
                                    
                                if (Player->bEnsure) {
                                    s += u8"Bot";
                                } else {
                                    //ws +=
                                   s += Player->PlayerName.ToString();
                            if (Player->Health == 0.0f) {
                                s += u8" - Downed";
                                }
                                        }
                                        
                                        
                                        auto textSize = ImGui::CalcTextSize2(s.c_str(), 0, ((float) density / 25.0f));
//draw->AddTextStorke(NULL, 15.0f, (int) HeadSc.x - (textSize.x / 2), (int) sHeight - HeadSc.y - 33.817f, ToColor(Config.ColorsESP.PlayerID), playerid.c_str());
                            draw->AddTextStorke(DX4Font, 16.0f, (int) RootPosSC.x - (textSize.x / 2), RootPosSC.y, TextClr, s.c_str());
                                    }
							
						

                            if (Config.ESPMenu.Distance) {
                                           float boxHeight = abs(headPosSC.y - RootPosSC.y);
                                    float boxWidth = boxHeight * 0.65f;
                                    std::string s;
                                    
                                    

                            if (Config.ESPMenu.Distance) {       
                                s += "\n  ";
                                s += std::to_string((int)Distance);
                                s += "M";
                                
                            }
                            auto textSize = ImGui::CalcTextSize2(s.c_str(), 0, ((float) density / 25.0f));
//draw->AddTextStorke(NULL, 15.0f, (int) HeadSc.x - (textSize.x / 2), (int) sHeight - HeadSc.y - 33.817f, ToColor(Config.ColorsESP.PlayerID), playerid.c_str());
                            draw->AddTextStorke(DX4Font, 16.0f, (int) RootPosSC.x - (textSize.x / 2), RootPosSC.y, IM_COL32(255, 255, 255, 255), s.c_str());

                       }}}
					
                    
                    if (End)
{
    if (Actor->IsA(ASTExtraGameStateBase::StaticClass()))
    {
        auto InGame = (ASTExtraGameStateBase *)Actor;
        std::string s;
        if ((int)InGame->AliveTeamNum == 1)
        {
            std::vector<std::string> lines = {
                OBFUSCATE("Chicken Dinner With DX4 CHEATS - TOP #1")};

            float textPosY = 420; 
            for (const auto &line : lines)
            {
                auto textSize = ImGui::CalcTextSize(line.c_str(), 0, line.size());
                float textPosX = (glWidth - textSize.x) / 2;
                draw->AddText(DX4Font, ((float)density / 12.0f), ImVec2(textPosX, textPosY), IM_COL32(255, 0, 0, 255), line.c_str());
                textPosY += textSize.y + 25; 
            }
        }
    }
}                                                                    
                    
                    
					if (Config.ESPMenu.info) {     
                                if (Actor->IsA(ASTExtraGameStateBase::StaticClass())) {
                                auto InGame = (ASTExtraGameStateBase *) Actor;
                                std::string s;
                                std::string Info;
                                    
                                s += "\nReal Players: ";
                                s += std::to_string((int) InGame->PlayerNum);
                                s += "\nTotal Alive Players: " ;
                                s += std::to_string((int) InGame->AlivePlayerNum);
                                s += "\nMatch Time  : ";
                                s += std::to_string((int) InGame->ElapsedTime);
                                s += "s | ";
                                s += std::to_string((int) InGame->ElapsedTime / 60);
                                s += "m";
                  
                                draw->AddText({((float) density / 20.0f), 600}, IM_COL32(0, 255, 47, 255), s.c_str());
                                draw->AddText({((float) density / 20.0f), 600}, IM_COL32(0, 255, 47, 255), Info.c_str());
                                }
							}
                            
                            if (AllEsp){
                Config.ESPMenu.Line = true;
                Config.ESPMenu.Health = true;                 
                Config.ESPMenu.Skeleton = true;              
                Config.ESPMenu.Vehicle = true;                
                Config.ESPMenu.GrenadeWarn = true;
                Config.ESPMenu.Name = true;                
                Config.ESPMenu.Distance = true;  
                Config.ESPMenu.info = true;  
                                
                            }
                            
                            if (AllAim){                               
                Config.AimBot.Enable = true;                            
                Config.AimBot.RecoilComparison = true;
                Config.AimBot.VisCheck = true;
			    Config.AimBot.IgnoreKnocked = true;
                            }
					
                            
                            

                     
                            
                            
					if (Config.ESPMenu.Vehicle) {
                            if (Actor->IsA(ASTExtraVehicleBase::StaticClass())) {
                                auto Vehicle = (ASTExtraVehicleBase *) Actor;

                                if (!Vehicle->Mesh)
                                    continue;

                                float Distance = Vehicle->GetDistanceTo(localPlayer) / 100.f;

                                FVector2D vehiclePos;
                                if (W2S(Vehicle->K2_GetActorLocation(), &vehiclePos)) {
                                    std::string s = GetVehicleName(Vehicle);
                                    if (Config.ESPMenu.Vehicle) {
                                        s += " [";
                                        s += std::to_string((int) Distance);
                                        s += "m]";
                                    }

                                    draw->AddText(DX4Font, ((float) density / 15.0f), {vehiclePos.X, vehiclePos.Y}, ToColor(Config.ColorsESP.Vehicle), s.c_str());
                                }
                            }
                        }
						
						if (Config.ESPMenu.GrenadeWarn) {
                            if (Actor->IsA(ASTExtraGrenadeBase::StaticClass())) {
                                auto Grenade = (ASTExtraGrenadeBase *) Actor;
                                auto RootComponent = Actor->RootComponent;
                                if (!RootComponent)
                                    continue;
                                float Distance = Grenade->GetDistanceTo(localPlayer) / 100.f;

                                FVector2D grenadePos;

                                if (W2S(Grenade->K2_GetActorLocation(), &grenadePos)) {
                                    std::string s = "Grenade";
                                    s += "[";
                                    s += std::to_string((int) Distance);
                                    s += "M]";

                                    draw->AddText(DX4Font, ((float) density / 15.0f),
                                                  {grenadePos.X, grenadePos.Y},
                                                  IM_COL32(0, 255, 47, 255), s.c_str());
                                }
                            }
                        }
						
						if (Config.ESPMenu.LootBox) {
                            if (Actor->IsA(APickUpListWrapperActor::StaticClass())) {
                                auto LootBox = (APickUpListWrapperActor *) Actor;
                                auto RootComponent = Actor->RootComponent;
                                if (!RootComponent)
                                    continue;
                                float Distance = LootBox->GetDistanceTo(localPlayer) / 100.f;

                                FVector2D lootboxPos;
                                if (W2S(LootBox->K2_GetActorLocation(), &lootboxPos)) {
                                    std::string s = "LootBox";
                                    s += "[";
                                    s += std::to_string((int) Distance);
                                    s += "M]";

                                    draw->AddText(DX4Font, ((float) density / 15.0f),
                                                  {lootboxPos.X, lootboxPos.Y},
                                                  IM_COL32(0, 255, 47, 255), s.c_str());
                                }
                            }
                        }
						
						
						
   
				

					
					
                            
                        }
                    }
                }
                                
      
					
					
      
        
               
					
					

                   /* 	g_LocalController = localController;
           g_LocalPlayer = localPlayer;
            std::string s;
     if (totalEnemies > 0 || totalBots > 0) {
    s = "Enemy: ";
    s += std::to_string(totalEnemies);
    s += " | Bot: ";
    s += std::to_string(totalBots);
                } else {
                    s += "";
                    }
                    auto textSize1 = ImGui::CalcTextSize2(s.c_str(), 0, ((float)density / 30.5f));
                    // Draw stroke and main text
                 
                    
                    draw->AddText(DX4Font, ((float)density / 10.5f), {((float)glWidth / 2) - (textSize1.x / 2), 50 - 1}, IM_COL32_BLACK, s.c_str()); // Stroke
                    draw->AddText(DX4Font, ((float)density / 10.5f), {((float)glWidth / 2) - (textSize1.x / 2), 50}, IM_COL32(255, 10, 10, 255), s.c_str());
                    }
        }
    }*/

	g_LocalController = localController;
g_LocalPlayer = localPlayer;
    std::string s;
if (totalEnemies > 0 || totalBots > 0){
    s += "Enemy ";
    s += std::to_string(totalEnemies);
    s += " | ";
    s += std::to_string(totalBots);
    s += " Bot";
    
    float new_height = 23;
    float new_width = 143;

    float x1 = glWidth / 2 - new_width / 2;
    float y1 = 70;
    float x2 = glWidth / 2 + new_width / 2;
    float y2 = y1 + new_height;
    
 
    draw->AddText(DX4Font, ((float)density / 15.0f), ImVec2(x1 + 9 - 8, y1 + 5 - 5), IM_COL32_BLACK, s.c_str());
    draw->AddText(DX4Font, ((float)density / 15.0f), ImVec2(x1 + 9 - 8, y1 + 5 - 5), IM_COL32(255, 0, 0, 255), s.c_str());
    }
}
}
	}
	
	
	
		fps.update();
	
	}
std::string getClipboardText() {
    if (!g_App)
        return "";

    auto activity = g_App->activity;
    if (!activity)
        return "";

    auto vm = activity->vm;
    if (!vm)
        return "";

    auto object = activity->clazz;
    if (!object)
        return "";

    std::string result;

    JNIEnv *env;
    vm->AttachCurrentThread(&env, 0);
extern "C"
JNIEXPORT jstring JNICALL
Java_com_tg_SilentCheats_activity_LoginActivity_GetKey(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF(OBFUSCATE("https://telegram.me/@NINJA1OP")); // Link Owner
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_tg_SilentCheats_activity_MainActivity_GetKey(JNIEnv *env, jobject thiz) {
    return env->NewStringUTF(OBFUSCATE("https://telegram.me/@NINJA1OP")); // Link Owner
}
extern "C" JNIEXPORT jstring JNICALL
Java_com_tg_SilentCheats_activity_MainActivity_Dexter(JNIEnv *env, jobject thiz ) {
    return env->NewStringUTF(OBFUSCATE("https://github.com/ONLINE-MOD/ONLINE-LIB/raw/main/loader.zip")); //Bypass Upload Url Link
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_tg_SilentCheats_activity_MainActivity_exdate(JNIEnv *env, jclass clazz) {
    return env->NewStringUTF(exdate.c_str());
}

const char *GetAndroidID(JNIEnv *env, jobject context) {
    jclass contextClass = env->FindClass("android/content/Context");
    jmethodID getContentResolverMethod = env->GetMethodID(contextClass,"getContentResolver","()Landroid/content/ContentResolver;");
    jclass settingSecureClass = env->FindClass("android/provider/Settings$Secure");
    jmethodID getStringMethod = env->GetStaticMethodID(settingSecureClass,"getString", "(Landroid/content/ContentResolver;Ljava/lang/String;)Ljava/lang/String;");

    auto obj = env->CallObjectMethod(context, getContentResolverMethod);
    auto str = (jstring) env->CallStaticObjectMethod(settingSecureClass, getStringMethod, obj,env->NewStringUTF("android_id"));
    return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceModel(JNIEnv *env) {
    jclass buildClass = env->FindClass("android/os/Build");
    jfieldID modelId = env->GetStaticFieldID(buildClass, "MODEL","Ljava/lang/String;");

    auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceBrand(JNIEnv *env) {
    jclass buildClass = env->FindClass("android/os/Build");
    jfieldID modelId = env->GetStaticFieldID(buildClass, "BRAND","Ljava/lang/String;");

    auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetPackageName(JNIEnv *env, jobject context) {
    jclass contextClass = env->FindClass("android/content/Context");
    jmethodID getPackageNameId = env->GetMethodID(contextClass, "getPackageName","()Ljava/lang/String;");

    auto str = (jstring) env->CallObjectMethod(context, getPackageNameId);
    return env->GetStringUTFChars(str, 0);
}

const char *GetDeviceUniqueIdentifier(JNIEnv *env, const char *uuid) {
    jclass uuidClass = env->FindClass("java/util/UUID");

    auto len = strlen(uuid);

    jbyteArray myJByteArray = env->NewByteArray(len);
    env->SetByteArrayRegion(myJByteArray, 0, len, (jbyte *) uuid);

    jmethodID nameUUIDFromBytesMethod = env->GetStaticMethodID(uuidClass,"nameUUIDFromBytes","([B)Ljava/util/UUID;");
    jmethodID toStringMethod = env->GetMethodID(uuidClass, "toString","()Ljava/lang/String;");

    auto obj = env->CallStaticObjectMethod(uuidClass, nameUUIDFromBytesMethod, myJByteArray);
    auto str = (jstring) env->CallObjectMethod(obj, toStringMethod);
    return env->GetStringUTFChars(str, 0);
}

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *) userp;

    mem->memory = (char *) realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        return 0;
    }

    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}
std::string CalcMD5(std::string s) {
    std::string result;

    unsigned char hash[MD5_DIGEST_LENGTH];
    char tmp[4];

    MD5_CTX md5;
    MD5_Init(&md5);
    MD5_Update(&md5, s.c_str(), s.length());
    MD5_Final(hash, &md5);
    for (unsigned char i : hash) {
        sprintf(tmp, "%02x", i);
        result += tmp;
    }
    return result;
}

std::string CalcSHA256(std::string s) {
    std::string result;

    unsigned char hash[SHA256_DIGEST_LENGTH];
    char tmp[4];

    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, s.c_str(), s.length());
    SHA256_Final(hash, &sha256);
    for (unsigned char i : hash) {
        sprintf(tmp, "%02x", i);
        result += tmp;
    }
    return result;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_tg_SilentCheats_activity_LoginActivity_Check(JNIEnv *env, jclass clazz, jobject mContext, jstring mUserKey) {
    auto user_key = env->GetStringUTFChars(mUserKey, 0);
    std::string hwid = user_key;
    hwid += GetAndroidID(env, mContext);
    hwid += GetDeviceModel(env);
    hwid += GetDeviceBrand(env);
    std::string UUID = GetDeviceUniqueIdentifier(env, hwid.c_str());
    std::string errMsg;
    struct MemoryStruct chunk{};
    chunk.memory = (char *) malloc(1);
    chunk.size = 0;

    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if (curl) {
        char lol[1000];
        sprintf(lol,OBFUSCATE("https://public.vip-pro.site/public/connect"));
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(curl, CURLOPT_URL, lol);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Accept: application/json");
        headers = curl_slist_append(headers,"Content-Type: application/x-www-form-urlencoded");
        headers = curl_slist_append(headers, "Charset: UTF-8");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        char data[4096];
        sprintf(data, "game=PUBG&user_key=%s&serial=%s", user_key, UUID.c_str());
        curl_easy_setopt(curl, CURLOPT_POST, 1);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &chunk);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYSTATUS, 0);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "AbsoluteX/2.0");
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            try {
                json result = json::parse(chunk.memory);
                auto STATUS = std::string{"status"};
                if (result[STATUS] == true) {
                    auto DATA = std::string{"data"};
                    auto TOKEN = std::string{"token"};
                    auto RNG = std::string{"rng"};
                    std::string token = result[DATA][TOKEN].get<std::string>();
                    time_t rng = result[DATA][RNG].get<time_t>();
                    exdate = result["data"]["EXP"].get<std::string>();
                    if (rng + 30 > time(0)) {
                        std::string auth = "PUBG";
                        auth += "-";
                        auth += user_key;
                        auth += "-";
                        auth += UUID;
                        auth += "-";
                        auth += "Vm8Lk7Uj2JmsjCPVPVjrLa7zgfx3uz9E";
                        std::string outputAuth = CalcMD5(auth);
                        g_Token = token;
                        g_Auth = outputAuth;
                        bValid = g_Token == g_Auth;
                        lolo = true;
                        if (bValid && lolo) {
                            printf(OBFUSCATE("Login Success \n"));
                        }
                    }
                } else {
                    auto REASON = std::string{"reason"};
                    errMsg = result[REASON].get<std::string>();
                }
            } catch (json::exception &e) {
                errMsg = e.what();
            }
        } else {
            errMsg = curl_easy_strerror(res);
        }
    }
    curl_easy_cleanup(curl);
    return bValid ? env->NewStringUTF("OK") : env->NewStringUTF(errMsg.c_str());
    return 0;
}

  static bool DX4 = false;
						
						
EGLBoolean (*orig_CGContextFlush)(EGLDisplay dpy, EGLSurface surface);
EGLBoolean _CGContextFlush(EGLDisplay dpy, EGLSurface surface)
{
    eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);

    screenWidth = ANativeWindow_getWidth(g_App->window);
    screenHeight = ANativeWindow_getHeight(g_App->window);
    density = AConfiguration_getDensity(g_App->config);

    if (!initImGui) {
        InitTexture();   
        ImGui::CreateContext();

        ImGui::StyleColorsDark();

	auto& Style = ImGui::GetStyle();
        Style.WindowRounding = 12.000f;
    Style.WindowTitleAlign = ImVec2(0.500f, 0.500f);
    Style.FramePadding = ImVec2(4.000f, 4.000f);
    Style.FrameRounding = 7.000f;
    Style.ItemInnerSpacing = ImVec2(17.000f, 4.000f);
	Style.GrabRounding = 12.000f;
		
        ImVec4 *colors = Style.Colors;
  Style.Colors[ImGuiCol_WindowBg] = ImVec4(0.076f, 0.076f, 0.076f, 0.941f);
  Style.Colors[ImGuiCol_Border] = ImVec4(1.000f, 1.000f, 1.000f, 0.500f);
  Style.Colors[ImGuiCol_FrameBg] = ImVec4(0.604f, 0.575f, 0.575f, 0.941f);
  Style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.980f, 0.260f, 0.260f, 0.400f);
  Style.Colors[ImGuiCol_FrameBgActive] = ImVec4(1.000f, 0.285f, 0.124f, 0.941f);
  Style.Colors[ImGuiCol_CheckMark] = ImVec4(0.000f, 0.000f, 0.000f, 0.941f);
  Style.Colors[ImGuiCol_Button] = ImVec4(0.195f, 0.179f, 0.179f, 1.000f);
  Style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.000f, 0.000f, 0.000f, 1.000f);
  Style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.000f, 0.000f, 0.000f, 1.000f);
		
        ImGui_ImplAndroid_Init();
        ImGui_ImplOpenGL3_Init("#version 300 es");

        ImGuiIO &io = ImGui::GetIO();

        io.ConfigWindowsMoveFromTitleBarOnly = true;
        io.IniFilename = NULL;
        
        
        static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0 };
        ImFontConfig icons_config;

        ImFontConfig CustomFont;
        CustomFont.FontDataOwnedByAtlas = false;

        icons_config.MergeMode = true;
        icons_config.PixelSnapH = true;
        icons_config.OversampleH = 2.5;
        icons_config.OversampleV = 2.5;

     io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t *>(Custom), sizeof(Custom), 18.0f, &CustomFont);
        DX4Font = io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 30.0f, &icons_config, icons_ranges);

        ImFontConfig cfg;
        cfg.SizePixels = ((float) density / 20.0f);
        io.Fonts->AddFontDefault(&cfg);

memset(&Config, 0, sizeof(sConfig));

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~{ @DX4_CHEATS }~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //

        
        Config.ColorsESP.Line = CREATE_COLOR(251, 255, 0, 255);
        Config.ColorsESP.Box = CREATE_COLOR(255, 255, 255, 155);
        Config.ColorsESP.Name = CREATE_COLOR(255, 0, 0, 255);
        Config.ColorsESP.Skeleton = CREATE_COLOR(251, 255, 0, 255);
        Config.ColorsESP.Distance = CREATE_COLOR(255, 0, 255, 255);
		Config.ColorsESP.Vehicle = CREATE_COLOR(0, 255, 47, 255);
		Config.ColorsESP.Fov = CREATE_COLOR(0, 255, 47, 255);
		Config.AimBot.Recc = 1.174f;
		Config.AimBot.Meter = 150.0f;//Aimbot meter
		
        initImGui = true;
    }


    ImGuiIO &io = ImGui::GetIO();


    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(glWidth, glHeight);
    ImGui::NewFrame();

            
        static bool ShowMainMenu;
DrawESP(ImGui::GetBackgroundDrawList(), glWidth, glHeight);
        if (ShowMainMenu == false){
    if (ImGui::Begin(OBFUSCATE(" open" ), 0,ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoMove)) {
    if(ImGui::InvisibleButton("open", ImVec2(100, 100) )) {
    ShowMainMenu = true;
    }}}
        //الحجم
        ImGui::SetNextWindowSize(ImVec2(350.000f, 350.000f), ImGuiCond_Once);
        
        static bool isLogin = false;
            static std::string err;
            if (!isLogin) {
                static ImVec4 color1 = ImVec4(0.961f, 0.106f, 0.083f, 1.000f);
    static ImVec4 color2 = ImVec4(1.000f, 0.000f, 0.000f, 1.000f);
    static ImVec4 color3 = ImVec4(0.017f, 1.000f, 0.911f, 1.000f);
    static ImVec4 color4 = ImVec4(0.000f, 1.000f, 0.987f, 1.000f);
    ImVec2 P1, P2;
    ImDrawList* pDrawList;
    const auto& CurrentWindowPos = ImGui::GetWindowPos();
    const auto& pWindowDrawList = ImGui::GetWindowDrawList();
    const auto& pBackgroundDrawList = ImGui::GetBackgroundDrawList();
    const auto& pForegroundDrawList = ImGui::GetForegroundDrawList();
    float animTime = ImGui::GetTime();
    float animDuration = 1.0f;
    float t = fmodf(animTime, animDuration) / animDuration;
    P1 = ImVec2(0.000f, 0.000f);
    P1.x += CurrentWindowPos.x;
    P1.y += CurrentWindowPos.y;
    P2 = ImVec2(500.000f, 250.000f);
    P2.x += CurrentWindowPos.x;
    P2.y += CurrentWindowPos.y;
    pDrawList = pWindowDrawList;
                ImGui::Text("Please Login! (Copy Key to Clipboard)");

                ImGui::PushItemWidth(-1);
                static char s[64];
                ImGui::InputText("##key", s, sizeof s);
                // auto paste
                auto key = getClipboardText();
                strncpy(s, key.c_str(), sizeof s);
                // auto login

                err = Login(s);
                if (err == "OK") {
                    PlaySoundYaserMod(LOGIN.c_str());
                    isLogin = bValid && g_Auth == g_Token;
                }
                ImGui::PopItemWidth();

                ImGui::PushItemWidth(-1);
                if (ImGui::Button(" Paste Key  ", ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {
                    auto key = getClipboardText();
                    strncpy(s, key.c_str(), sizeof s);
                }
                ImGui::PopItemWidth();

                ImGui::PushItemWidth(-1);


                if (ImGui::Button("Login", ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {
                    err = Login(s);
                    if (err == "OK") {
                        isLogin = bValid && g_Auth == g_Token;
                        
                    }
                }
                ImGui::PopItemWidth();

                if (!err.empty() && err != "OK") {
                    ImGui::Text("Error: %s", err.c_str());
                       
                }

                ImGui::PopItemWidth();


            } else {
             
                                      if(ShowMainMenu){
             static bool p_open = false;
           char buf[128];
    sprintf(buf, (OBFUSCATE("DX4 HAX | FPS %0.2f ###AnimatedTitle")),(io.Framerate), ImGui::GetFrameCount());

    ImGui::Begin(buf, &ShowMainMenu, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);        
    
        ImGui::SetNextWindowSize(ImVec2(350.000f, 353.000f), ImGuiCond_Once);
                        
  ImVec2 P1, P2;
    ImDrawList* pDrawList;
    const auto& CurrentWindowPos = ImGui::GetWindowPos();
    const auto& pWindowDrawList = ImGui::GetWindowDrawList();
    const auto& pBackgroundDrawList = ImGui::GetBackgroundDrawList();
    const auto& pForegroundDrawList = ImGui::GetForegroundDrawList();

    P1 = ImVec2(1.000f, 300.000f);
    P1.x += CurrentWindowPos.x;
    P1.y += CurrentWindowPos.y;
    P2 = ImVec2(400.000f, 80.000f);
    P2.x += CurrentWindowPos.x;
    P2.y += CurrentWindowPos.y;
    pDrawList = pWindowDrawList;
    pDrawList->AddRectFilled(P1, P2, ImColor(0.169f, 0.153f, 0.153f, 1.000f), 0.000f);

    P1 = ImVec2(15.000f, 38.000f);
    P1.x += CurrentWindowPos.x;
    P1.y += CurrentWindowPos.y;
    P2 = ImVec2(335.000f, 73.000f);
    P2.x += CurrentWindowPos.x;
    P2.y += CurrentWindowPos.y;
    pDrawList = pWindowDrawList;
    pDrawList->AddRectFilled(P1, P2, ImColor(0.498f, 0.444f, 0.444f, 1.000f), 0.000f);

    
  
  if (!g_Token.empty() && !g_Auth.empty() && g_Token == g_Auth) {
      
  ImGui::SetCursorPos(ImVec2(120.000f, 10.000f));
	ImGui::Text(OBFUSCATE(" DX4 CHEATS"));
  
  
      static int DX44 = 0;
    ImGui::SetCursorPos(ImVec2(8.000f, 35.000f));
	if (ImGui::Button("Player", ImVec2(80.000f, 40.000f))){
      DX44 = 0;
}
    ImGui::SetCursorPos(ImVec2(92.000f, 35.000f));
	if (ImGui::Button("Aimbot", ImVec2(80.000f, 40.000f))){
      DX44 = 1;
}
    ImGui::SetCursorPos(ImVec2(175.000f, 35.000f));
	if (ImGui::Button("Extra", ImVec2(80.000f, 40.000f))){
      DX44 = 2;
}
    ImGui::SetCursorPos(ImVec2(259.000f, 35.000f));
	if (ImGui::Button("Settings", ImVec2(80.000f, 40.000f))){
      DX44 = 3;
}

    ImGui::SetCursorPos(ImVec2(10.000f, 305.000f));
	if (ImGui::Button("EXIT", ImVec2(330.000f, 40.000f))){
        ShowMainMenu = false;
    }

if (DX44 == 0) {
    ImGui::SetCursorPos(ImVec2(15.000f, 100.000f));
    ImGui::Checkbox("Show Line", &Config.ESPMenu.Line);

    ImGui::SetCursorPos(ImVec2(15.000f, 140.000f));
    ImGui::Checkbox("Show Name", &Config.ESPMenu.Name);

    ImGui::SetCursorPos(ImVec2(174.000f, 100.000f));
    ImGui::Checkbox("Show Health", &Config.ESPMenu.Health);

    ImGui::SetCursorPos(ImVec2(174.000f, 140.000f));
    ImGui::Checkbox("Show Distance", &Config.ESPMenu.Distance);

    ImGui::SetCursorPos(ImVec2(15.000f, 180.000f));
    ImGui::Checkbox("Show Skeleton", &Config.ESPMenu.Skeleton);

    ImGui::SetCursorPos(ImVec2(174.000f, 180.000f));
    ImGui::Checkbox("Show Vehicle", &Config.ESPMenu.Vehicle);

    ImGui::SetCursorPos(ImVec2(15.000f, 220.000f));
    ImGui::Checkbox("Show Info", &Config.ESPMenu.info);

    ImGui::SetCursorPos(ImVec2(174.000f, 220.000f));
    ImGui::Checkbox("Show Grande", &Config.ESPMenu.GrenadeWarn);

  }
  
  if (DX44 == 1) {
    ImGui::SetCursorPos(ImVec2(15.000f, 100.000f));
    ImGui::Checkbox("Aim-Tracking", &Config.AimBot.Enable);

    ImGui::SetCursorPos(ImVec2(174.000f, 100.000f));
    ImGui::Checkbox("Aim Recoil", &Config.AimBot.RecoilComparison);

    ImGui::SetCursorPos(ImVec2(15.000f, 150.000f));
    ImGui::Text("TARGET :-");
    ImGui::SameLine();
    static const char* targets[] = { "Head", "Chest" };
    ImGui::Combo("##Target", (int*)&Config.AimBot.Target, targets, 2, -1);

    ImGui::SetCursorPos(ImVec2(15.000f, 200.000f));
    ImGui::Checkbox("Visiblity Check", &Config.AimBot.VisCheck);

    ImGui::SetCursorPos(ImVec2(174.000f, 200.000f));
    ImGui::Checkbox("Ignore knocked", &Config.AimBot.IgnoreKnocked);

    ImGui::SetCursorPos(ImVec2(15.000f, 240.000f));
    ImGui::Checkbox("Ignore Bots", &Config.AimBot.IgnoreBot);

  }
  
  if (DX44 == 2) {
      
      
  ImGui::SetCursorPos(ImVec2(50.000f, 160.000f));
  ImGui::Text("S o o n ..........");
  
  
                                         
  
  }
  
  if (DX44 == 3) {
      
      
  ImGui::SetCursorPos(ImVec2(50.000f, 160.000f));
  ImGui::Text("S o o n ..........");
  
  
                                         
  
  }
  
  
			    		  }else{
        ImGui::Text("Bhag Bsdk Teri Maa Ki Chut Krle Crack");
				    }
           }
          
		}
        ImGui::End();
    ImGui::Render();
						
						
						
						
						
						
						
						
						
						
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    return orig_CGContextFlush(dpy, surface);
}
        

        #define SLEEP_TIME 1000LL / 60LL
        [[noreturn]] void *maps_thread(void *) {
	    while (true) {
        auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
		
	    if (Config.HighRisk.Ipad) {
        auto objs = UObject::GetGlobalObjects();
        for (int i = 0; i < objs.Num(); i++) {
        auto Object = objs.GetByIndex(i);
        if (isObjectInvalid(Object))
        continue;
        if (Object->IsA(ULocalPlayer::StaticClass())) {
        auto playerChar = (ULocalPlayer *) Object;      
        playerChar->AspectRatioAxisConstraint = EAspectRatioAxisConstraint::AspectRatio_MaintainYFOV;
        }     
        }
        }
		
        if (Config.HighRisk.NoFog) {
        auto objs = UObject::GetGlobalObjects();
        for (int i = 0; i < objs.Num(); i++) {
        auto Object = objs.GetByIndex(i);
        if (isObjectInvalid(Object))
        continue;
        if (Object->IsA(UExponentialHeightFogComponent::StaticClass())) {
        auto playerChar = (UExponentialHeightFogComponent *) Object;
        playerChar->SetFogMaxOpacity(0.0f);
        playerChar->SetFogDensity(0.0f);
        playerChar->SetFogHeightFalloff(0.0f);
        playerChar->SetFogCutoffDistance(0.0f);
        playerChar->SetStartDistance(0.0f);
        }
		}
        }
        
        
               
		
          if(Config.V1){     
auto objs = UObject::GetGlobalObjects();
for (int i = 0; i < objs.Num(); i++){
auto Object = objs.GetByIndex(i);
if (isObjectInvalid(Object))
continue;
if(Object->IsA(USTExtraGameInstance::StaticClass())) {
auto playerChar = (USTExtraGameInstance *) Object;          
playerChar->UserDetailSetting.PUBGDeviceFPSDef = 60;               
playerChar->UserDetailSetting.PUBGDeviceFPSLow = 60;        
playerChar->UserDetailSetting.PUBGDeviceFPSMid = 60;         
playerChar->UserDetailSetting.PUBGDeviceFPSHigh = 60; 
playerChar->UserDetailSetting.PUBGDeviceFPSHDR = 60;               
playerChar->UserDetailSetting.PUBGDeviceFPSUltralHigh = 60;
  }
}}
  if(Config.V2){     
auto objs = UObject::GetGlobalObjects();
for (int i = 0; i < objs.Num(); i++){
auto Object = objs.GetByIndex(i);
if (isObjectInvalid(Object))
continue;
if(Object->IsA(USTExtraGameInstance::StaticClass())) {
auto playerChar = (USTExtraGameInstance *) Object;          
playerChar->UserDetailSetting.PUBGDeviceFPSDef = 90;               
playerChar->UserDetailSetting.PUBGDeviceFPSLow = 90;        
playerChar->UserDetailSetting.PUBGDeviceFPSMid = 90;         
playerChar->UserDetailSetting.PUBGDeviceFPSHigh = 90; 
playerChar->UserDetailSetting.PUBGDeviceFPSHDR = 90;               
playerChar->UserDetailSetting.PUBGDeviceFPSUltralHigh = 90;
  }
}}

  if(Config.V3){     
auto objs = UObject::GetGlobalObjects();
for (int i = 0; i < objs.Num(); i++){
auto Object = objs.GetByIndex(i);
if (isObjectInvalid(Object))
continue;
if(Object->IsA(USTExtraGameInstance::StaticClass())) {
auto playerChar = (USTExtraGameInstance *) Object;          
playerChar->UserDetailSetting.PUBGDeviceFPSDef = 120;               
playerChar->UserDetailSetting.PUBGDeviceFPSLow = 120;        
playerChar->UserDetailSetting.PUBGDeviceFPSMid = 120;         
playerChar->UserDetailSetting.PUBGDeviceFPSHigh = 120; 
playerChar->UserDetailSetting.PUBGDeviceFPSHDR = 120;               
playerChar->UserDetailSetting.PUBGDeviceFPSUltralHigh = 120;
  }
}}
if (PARACHUTE) {
auto objs = UObject::GetGlobalObjects();
for (int i = 0;i < objs.Num();i++) {
auto Object = objs.GetByIndex(i);
if (isObjectInvalid(Object))
continue;
UCharacterParachuteComponent *ParachuteComponent = g_LocalPlayer->ParachuteComponent;
if (ParachuteComponent)
{
ParachuteComponent->CurrentFallSpeed = 9999.9f;
}}}
                     
		
        std::vector<sRegion> tmp;
        char line[512];
        FILE *f = fopen("/proc/self/maps", "r");
        if (f) {
        while (fgets(line, sizeof line, f)) {
        uintptr_t start, end;
        char tmpProt[16];
        if (sscanf(line, "%" PRIXPTR "-%" PRIXPTR " %16s %*s %*s %*s %*s", &start, &end, tmpProt) > 0) {
        if (tmpProt[0] != 'r') {
        tmp.push_back({start, end});
        }
        }
        }
        fclose(f);
        }
        trapRegions = tmp;
        auto td = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - t1;
        std::this_thread::sleep_for(std::chrono::milliseconds(std::max(std::min(0LL, SLEEP_TIME - td), SLEEP_TIME)));
        }
        }

	
		void FixGameCrash()
{
    system("rm -rf /data/data/com.pubg.imobile/files");
    system("rm -rf /data/data/com.pubg.imobile/files/ano_tmp");
    system("touch /data/data/com.pubg.imobile/files/ano_tmp");
    system("chmod 000 /data/data/com.pubg.imobile/files/ano_tmp");
    system("rm -rf /data/data/com.pubg.imobile/files/obblib");
    system("touch /data/data/com.pubg.imobile/files/obblib");
    system("chmod 000 /data/data/com.pubg.imobile/files/obblib");
    system("rm -rf /data/data/com.pubg.imobile/files/xlog");
    system("touch /data/data/com.pubg.imobile/files/xlog");
    system("chmod 000 /data/data/com.pubg.imobile/files/xlog");
    system("rm -rf /data/data/com.pubg.imobile/app_bugly");
    system("touch /data/data/com.pubg.imobile/app_bugly");
    system("chmod 000 /data/data/com.pubg.imobile/app_bugly");
    system("rm -rf /data/data/com.pubg.imobile/app_crashrecord");
    system("touch /data/data/com.pubg.imobile/app_crashrecord");
    system("chmod 000 /data/data/com.pubg.imobile/app_crashrecord");
    system("rm -rf /data/data/com.pubg.imobile/app_crashSight");
    system("touch /data/data/com.pubg.imobile/app_crashSight");
    system("chmod 000 /data/data/com.pubg.imobile/app_crashSight");
}
		
//sdk bypass

 

void *main_thread(void *) {
    FixGameCrash();
    //LOGI("%s",Gamepackage);
    pid_t Pid = getpid();
    UE4 = Tools::GetBaseAddress("libUE4.so");
    while (!UE4) {
        UE4 = Tools::GetBaseAddress("libUE4.so");
        sleep(1);
    }
LOGI("libUE4.so: %p", UE4);
    while (!g_App) {
        g_App = *(android_app **) (UE4 + GNativeAndroidApp_Offset);
        sleep(1);
    }

    FName::GNames = GetGNames();
    while (!FName::GNames) {
        FName::GNames = GetGNames();
        sleep(1);
    }
    UObject::GUObjectArray = (FUObjectArray *) (UE4 + GUObject_Offset);

DobbyHook((void *)DobbySymbolResolver("/system/lib64/libandroid.so", "ANativeWindow_getWidth"), (void *)_ANativeWindow_getWidth, (void **)&orig_ANativeWindow_getWidth);
    DobbyHook((void *)DobbySymbolResolver("/system/lib64/libandroid.so", "ANativeWindow_getHeight"), (void *)_ANativeWindow_getHeight, (void **)&orig_ANativeWindow_getHeight);
    DobbyHook((void *)DobbySymbolResolver("/system/lib64/libinput.so", "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE"), (void *)onInputEvent, (void **)&orig_onInputEvent);
    A64HookFunction((void *)(UE4+SwapBuffers), (void *)_CGContextFlush, (void **)&orig_CGContextFlush);
    pthread_t t;
    pthread_create(&t, 0, maps_thread, 0);
    items_data = json::parse(JSON_ITEMS);
    return 0;
}

	#include "RemapTools.h"
__attribute__((constructor)) void _init() {
    pthread_t t;
    pthread_t ptid;
    pthread_t ptid1;
    pthread_create(&t, 0, main_thread, 0);



}
