
      dimensionedScalar rhoInfValue
      (
          transportProperties.lookup("rhoInf")
      );

      dimensionedScalar invrhoInf("invrhoInf",(1.0/rhoInfValue));

      volScalarField rhoInf
      (
          IOobject
          (
              "rho",
              runTime.timeName(),
              mesh,
              IOobject::NO_READ,
              IOobject::NO_WRITE
          ),
          mesh,
          rhoInfValue
      );

      volScalarField mu
      (
          IOobject
          (
              "mu",
              runTime.timeName(),
              mesh,
              IOobject::NO_READ,
              IOobject::NO_WRITE
          ),
          laminarTransport.nu()*rhoInfValue
      );

// ----------------------------------------------------------------------------

      const word kinematicCloudName1
      (
          args.optionLookupOrDefault<word>("cloudName", "kinematicCloud1")
      );

      Info<< "Constructing kinematicCloud1 " << kinematicCloudName1 << endl;
      basicKinematicCollidingCloud kinematicCloud1
      (
          kinematicCloudName1,
          rhoInf,
          U,
          mu,
          g
      );

