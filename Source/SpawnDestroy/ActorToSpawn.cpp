// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorToSpawn.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AActorToSpawn::AActorToSpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// create our default component
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComp"));

	// bind component and set physic effect
	SphereComp->SetupAttachment(RootComponent);
	SphereComp->SetSimulatePhysics(true);
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	StaticMeshComp->AttachToComponent(SphereComp, FAttachmentTransformRules::KeepRelativeTransform);
	ParticleComp->AttachToComponent(StaticMeshComp, FAttachmentTransformRules::KeepRelativeTransform);

	//set sphere's radius as a smaller size for static mesh component
	SphereComp->SetSphereRadius(16.0f);

	//set scale and translate to match the radius
	StaticMeshComp->SetRelativeLocation(FVector(0.0f, 0.0f, -12.0f));
	StaticMeshComp->SetRelativeScale3D(FVector(0.25, 0.25, 0.25));

	// using construct helper to set static mesh as a sphere
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	StaticMeshComp->SetStaticMesh(SphereMeshAsset.Object);

	//using constructor helper to set particle component as a fire particle
	static ConstructorHelpers::FObjectFinder<UParticleSystem>ParticleCompAsset(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));
	ParticleComp->SetTemplate(ParticleCompAsset.Object);

}



