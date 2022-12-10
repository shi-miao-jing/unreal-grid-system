// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#pragma once

#include "CoreMinimal.h"
#include "SnapAxis.h"
#include "GameFramework/Actor.h"
#include "GridSystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGridTileSizeChangedDelegate);

UCLASS()
class GRIDSYSTEMEXAMPLE_API AGridSystem : public AActor
{
	GENERATED_BODY()
	
public:	
	AGridSystem();


private:
	UFUNCTION()
	static int GetClosestTileCoordinate(
		const int Coordinate,
		const int Distance,
		const int TileSize);
	
public:
	UPROPERTY(BlueprintAssignable)
	FGridTileSizeChangedDelegate GridTileSizeChangedDelegate;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* SceneComponent;
	
	// UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// UDecalComponent* DecalComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	float TileSize = 50;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	FVector Position;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	FLinearColor Color;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	FLinearColor Tint;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	FLinearColor SelectionColor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	float Brightness = 200.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	bool Visible = true;
	
	// Calculates the snap location.
	UFUNCTION(BlueprintCallable)
	static FVector GetSnapLocation(
		const FVector HitLocation,
		const FSnapAxis SnapAxis,
		const int GridTileSize = 50);
};
