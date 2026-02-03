// clang-format off

// Below are some real examples of Valve source code from Half-Life, TF2, and CS:GO.
// Text has been lightly censored.

// ===========================================================================

if ( FindSOCache( steamID ) != NULL )
{
    EmitError( SPEW_GC, "HOLY F******* S*** WE ARE DUPLICATING SO CACHES [%s]\n", steamID.Render() );
}

// ===========================================================================

void CPasstimeGun::AttackInputState::Update( int held, int pressed, int released )
{
    if ( eButtonState == BUTTONSTATE_DISABLED )
    {
        return;
    }
    
    // this exists so i don't have to do lots of confusing "if button pressed and my
    // charge timer is < curtime and some other b***s*** then do thing unless some
    // other b***s*** and so on
    // other can go directly from RELEASED to PRESSED without visiting UP along the way
}

// ===========================================================================

///////////////////////////////////////////////////////////////////////////////
//
//                          Windows UTF8 filename handling
//
// Windows stupidly treats 8-bit filenames as some dopey code page,
// rather than UTF-8 like we want to use. So, ok, we have to
// convert them to WCHAR explicitly and call WCHAR versions of the
// file functions. So, ok, we do.

// ===========================================================================

// Keep moving the tongue to its dead position
// FIXME: This stupid algorithm is necessary because
// I can't seem to get reproduceable behavior from Springs
bool bFoundInPosition = false;
float flHinge = m_vecHook.Get().x - m_vecFlp.Get().x;
if ( fabs( flHinge ) > 20.0f )
{
    float flNewAltitude;
    float dt = gpGlobals->curtime - GetLastThink();
    if ( m_flAltitude >= goalAltitude ){}
}

// ===========================================================================

DeathNoticePlayer    Killer;
DeathNoticePlayer    Victim;
CHudTexture         *IconDeath;
bool                bKilled;
float               flDisplayTime;

// When I see a boolean like this, I know serious b***s*** is afoot!

// ===========================================================================

// Clear that m*****f***** out
m_vecSolidClipListeners.RemoveAll();

// ===========================================================================

// Hrm, we didn't link up to correct type!!!
Assert( 0 );
// Delete right away since it's f***** up
return true;

if ( beam->IsFlagSet( EFL_KILLME ) )
{
    // Don't delete right away
    AddFlag( EFL_KILLME );
    return false;

// Go ahead and delete if it's not short-lived
return true;
}

// ===========================================================================

// This is utterly f****** r*******.
pBox->SetFgColor( tanDark );
pBox->SetDefaultColor( tanDark, pBox->GetBgColor() );
pBox->SetArmedColor( tanDark, pBox->GetBgColor() );
pBox->SetDepressedColor( tanDark, pBox->GetBgColor() );
pBox->SetSelectedColor( tanDark, pBox->GetBgColor() );
pBox->SetHighlightColor( tanDark );
pBox->GetCheckImage()->SetColor( tanDark );
break;
case O_STRING:
case O_NUMBER:

// ===========================================================================

char sprFmt[4];
Q_snprintf(sprFmt, 4, "*.vmt");
Q_snprintf(szName, MAX_PATH, "%s.vmt", szName);
//Strict: I am being so lenient on this: I prolly have to strip the other string or something.
//Q_strcat( szName, sprFmt, MAX_PATH );

// ===========================================================================

float3 worldSpaceNormal;
// Make the unwapped version not so f****** stupid and not need tangentSpaceTranspose you knob.
worldSpaceNormal = mul( normal, i.tangentSpaceTranspose );

// I don't know why, I don't want to know why, I shouldn't
// have to wonder why, but for whatever reason this stupid
// panel isn't laying out correctly unless we do this terribleness
InvalidateLayout( true );
m_pContents->InvalidateLayout( true, true );

GTFGCClientSystem()->SetLocalPlayerSquadSurplus( false );
WriteControls();
m_pContents->UpdateControls();

Panel* pPvPRankPanel = FindChildByName( "RankPanel", true );
if ( pPvPRankPanel )
{}

// ===========================================================================
