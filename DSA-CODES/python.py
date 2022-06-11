for i in range (0 , 50 ) :
    a1 = i + 10
    b1 = -i + 10
    c1 = 0.1256*(i + 10)
    g1 = -1.59*(i + 10 )
    f1 = (-a1*(1.59)*2 -b1(1.55+i)**2-2*g1*1.59 -c1)/(3.1 + 2*i)
    a2 = a1
    b2 = b1
    g2 = g1
    c2 = -0.1288*(i+10)
    f2 = (-a2*(1.59)*2 -b2(1.63+i)**2-2*g2*1.59 -c2)/(3.26 + 2*i)
    mdb.models['Model-1'].ConstrainedSketch(name='_profile_', sheetSize=10.0)
    mdb.models['Model-1'].sketches['_profile_'].Spot(point=(0.04, 0.0))
    mdb.models['Model-1'].sketches['_profile_'].Spot(point=(0.56, (-f1 + ((f1)*2 - a1(0.56*2) -2*g1*0.56 -c1)*0.5)/b1))
    mdb.models['Model-1'].sketches['_profile_'].Spot(point=(1.07, (-f1 + ((f1)*2 - a1(1.07*2) -2*g1*1.07 -c1)*0.5)/b1))
    mdb.models['Model-1'].sketches['_profile_'].Spot(point=(1.59, 1.55 + i))
    mdb.models['Model-1'].sketches['_profile_'].Spot(point=(2.1, (-f1 + ((f1)*2 - a1(2.1*2) -2*g1*2.1 -c1)*0.5)/b1))
    mdb.models['Model-1'].sketches['_profile_'].Spot(point=(2.62, (-f1 + ((f1)*2 - a1(2.62*2) -2*g1*2.62 -c1)*0.5)/b1))
    mdb.models['Model-1'].sketches['_profile_'].Spot(point=(3.14, 0.0))
    mdb.models['Model-1'].sketches['_profile_'].Spot(point=(-0.04, 0.0))
    mdb.models['Model-1'].sketches['_profile_'].Spot(point=(0.5, (-f2 + ((f2)*2 - a2(0.5*2) -2*g2*0.5 -c2)*0.5)/b2))
    mdb.models['Model-1'].sketches['_profile_'].Spot(point=(1.04, (-f2 + ((f2)*2 - a2(1.04*2) -2*g2*1.04 -c2)*0.5)/b2))
    mdb.models['Model-1'].sketches['_profile_'].Spot(point=(1.59, 1.63 + i))
    mdb.models['Model-1'].sketches['_profile_'].Spot(point=(2.13, (-f2 + ((f2)*2 - a2(2.13*2) -2*g2*2.13 -c2)*0.5)/b2))
    mdb.models['Model-1'].sketches['_profile_'].Spot(point=(2.67, (-f2 + ((f2)*2 - a2(2.67*2) -2*g2*2.67 -c2)*0.5)/b2))
    mdb.models['Model-1'].sketches['_profile_'].Spot(point=(3.22, 0.0))
    mdb.models['Model-1'].sketches['_profile_'].Spline(points=((0.04, 0.0), 
    (0.56, (-f1 + ((f1)*2 - a1(0.56*2) -2*g1*0.56 -c1)0.5)/b1), (1.07, (-f1 + ((f1)2 - a1(1.07*2) -2*g1*1.07 -c1)0.5)/b1), (1.59, 1.55 + i), (2.1, (-f1 + ((f1)2 - a1(2.1*2) -2*g1*2.1 -c1)0.5)/b1), ((2.62, -f1 + ((f1)2 - a1(2.62*2) -2*g1*2.61 -c1)*0.5)/b1), 
        (3.14,0)))
    mdb.models['Model-1'].sketches['_profile_'].Spline(points=((-0.04, 0.0), (
        0.5, (-f2 + ((f2)*2 - a2(0.5*2) -2*g2*0.5 -c2)0.5)/b), (1.04, (-f2 + ((f2)2 - a2(1.04*2) -2*g2*1.04 -c2)0.5)/b2), (1.59, 1.63+i), (2.13, (-f2 + ((f2)2 - a2(2.13*2) -2*g2*2.13 -c2)0.5)/b2), (2.67,(-f2 + ((f2)2 - a2(2.67*2) -2*g2*2.67 -c2)*0.5)/b2), 
        (3.22, 0)))
    mdb.models['Model-1'].sketches['_profile_'].Line(point1=(0.04, 0.0), point2=(
        -0.04, 0.0))
    mdb.models['Model-1'].sketches['_profile_'].HorizontalConstraint(
        addUndoState=False, entity=
        mdb.models['Model-1'].sketches['_profile_'].geometry[4])
    mdb.models['Model-1'].sketches['_profile_'].Line(point1=(3.14, 0.0), point2=(
        3.22, 0.0))
    mdb.models['Model-1'].sketches['_profile_'].HorizontalConstraint(
        addUndoState=False, entity=
        mdb.models['Model-1'].sketches['_profile_'].geometry[5])
    mdb.models['Model-1'].Part(dimensionality=THREE_D, name='Part-1', type=
        DEFORMABLE_BODY)
    mdb.models['Model-1'].parts['Part-1'].BaseSolidExtrude(depth=0.008, sketch=
        mdb.models['Model-1'].sketches['_profile_'])