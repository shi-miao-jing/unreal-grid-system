#pragma once

#include "SnapAxis.generated.h"

USTRUCT(BlueprintType, Category="Structs")
struct FSnapAxis
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool X = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Y = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Z = false;
};
