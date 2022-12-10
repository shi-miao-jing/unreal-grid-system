#include "GridSystem.h"
#include "SnapAxis.h"
#include "Components/DecalComponent.h"
#include "Kismet/KismetMathLibrary.h"

AGridSystem::AGridSystem()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	// DecalComponent = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComponent"));
	// DecalComponent->SetupAttachment(SceneComponent);
}

FVector AGridSystem::GetSnapLocation(
	const FVector HitLocation,
	const FSnapAxis SnapAxis,
	const int GridTileSize)
{
	if (GridTileSize == 0)
	{
		return FVector(0);
	}

	const int Distance = 2 * GridTileSize;
	
	int XCoordinate = UKismetMathLibrary::Round(HitLocation.X);
	int YCoordinate = UKismetMathLibrary::Round(HitLocation.Y);
	int ZCoordinate = UKismetMathLibrary::Round(HitLocation.Z);
	
	const int SnapCoordinateX = GetClosestTileCoordinate(XCoordinate, Distance, GridTileSize);
	const int SnapCoordinateY = GetClosestTileCoordinate(YCoordinate, Distance, GridTileSize);
	const int SnapCoordinateZ = GetClosestTileCoordinate(ZCoordinate, Distance, GridTileSize);

	if (SnapAxis.X == true)
	{
		XCoordinate = (XCoordinate / Distance) * Distance + SnapCoordinateX;
	}
	if (SnapAxis.Y == true)
	{
		YCoordinate = (YCoordinate / Distance) * Distance + SnapCoordinateY;
	}
	if (SnapAxis.Z == true)
	{
		ZCoordinate = (ZCoordinate / Distance) * Distance + SnapCoordinateZ;
	}

	return FVector(XCoordinate, YCoordinate, ZCoordinate);	
}

int AGridSystem::GetClosestTileCoordinate(
	const int Coordinate,
	const int Distance,
	const int TileSize)
{
	const int Result = Coordinate % Distance;

	if (Result >= TileSize)
	{
		return TileSize;
	}
	
	return 0;
}
