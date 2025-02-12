// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class BlasterEditorTarget : TargetRules
{
	public BlasterEditorTarget( TargetInfo Target) : base(Target)
	{
        CppStandard = CppStandardVersion.Default;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        IncludeOrderVersion = EngineIncludeOrderVersion.Latest;

        bLegacyParentIncludePaths = false;
        WindowsPlatform.bStrictConformanceMode = true;
        bValidateFormatStrings = true;

        Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "Blaster" } );
	}
}
