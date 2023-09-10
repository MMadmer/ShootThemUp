// Shoot Them Up game. All Rights Reserved.


#include "AI/Services/STUChangeWeaponService.h"
#include "Components/STUWeaponComponent.h"
#include "AIController.h"
#include "Kismet/KismetMathLibrary.h"

USTUChangeWeaponService::USTUChangeWeaponService()
{
	NodeName = "Change Weapon";
}

void USTUChangeWeaponService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	const auto Controller = OwnerComp.GetAIOwner();

	if (Controller)
	{
		const auto WeaponComponent = Controller->GetPawn()->FindComponentByClass<USTUWeaponComponent>();
		if (WeaponComponent && UKismetMathLibrary::RandomBoolWithWeight(Probability))
		{
			WeaponComponent->NextWeapon();
		}
	}

	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
