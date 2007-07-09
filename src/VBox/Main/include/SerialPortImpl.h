/** @file
 *
 * VirtualBox COM class implementation
 */

/*
 * Copyright (C) 2006-2007 innotek GmbH
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License as published by the Free Software Foundation,
 * in version 2 as it comes in the "COPYING" file of the VirtualBox OSE
 * distribution. VirtualBox OSE is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY of any kind.
 *
 * If you received this file as part of a commercial VirtualBox
 * distribution, then only the terms of your commercial VirtualBox
 * license agreement apply instead of the previous paragraph.
 */

#ifndef ____H_SERIALPORTIMPL
#define ____H_SERIALPORTIMPL

#include "VirtualBoxBase.h"

#include <VBox/cfgldr.h>

class Machine;

class ATL_NO_VTABLE SerialPort :
    public VirtualBoxBaseNEXT,
    public VirtualBoxSupportErrorInfoImpl <SerialPort, ISerialPort>,
    public VirtualBoxSupportTranslation <SerialPort>,
    public ISerialPort
{
public:

    struct Data
    {
        Data()
            : mSlot (0)
            , mEnabled(FALSE)
            , mIrq (4)
            , mIobase (0x3f8)
        {}

        bool operator== (const Data &that) const
        {
            return this == &that ||
                   (mSlot == that.mSlot &&
                    mEnabled == that.mEnabled &&
                    mIrq == that.mIrq &&
                    mIobase == that.mIobase);
        }

        ULONG mSlot;
        BOOL  mEnabled;
        ULONG mIrq;
        ULONG mIobase;
        Bstr  mPipe;
        BOOL  mServer;
    };

    VIRTUALBOXBASE_ADD_ERRORINFO_SUPPORT (SerialPort)

    DECLARE_NOT_AGGREGATABLE(SerialPort)

    DECLARE_PROTECT_FINAL_CONSTRUCT()

    BEGIN_COM_MAP(SerialPort)
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
        COM_INTERFACE_ENTRY(ISerialPort)
    END_COM_MAP()

    NS_DECL_ISUPPORTS

    DECLARE_EMPTY_CTOR_DTOR (SerialPort)

    HRESULT FinalConstruct();
    void FinalRelease();

    // public initializer/uninitializer for internal purposes only
    HRESULT init (Machine *aParent, ULONG aSlot);
    HRESULT init (Machine *aParent, SerialPort *aThat);
    HRESULT initCopy (Machine *parent, SerialPort *aThat);
    void uninit();

    // ISerialPort properties
    STDMETHOD(COMGETTER(Slot))    (ULONG     *aSlot);
    STDMETHOD(COMGETTER(Enabled)) (BOOL      *aEnabled);
    STDMETHOD(COMSETTER(Enabled)) (BOOL       aEnabled);
    STDMETHOD(COMGETTER(Irq))     (ULONG     *aIrq);
    STDMETHOD(COMSETTER(Irq))     (ULONG      aIrq);
    STDMETHOD(COMGETTER(Iobase))  (ULONG     *aIobase);
    STDMETHOD(COMSETTER(Iobase))  (ULONG      aIobase);
    STDMETHOD(COMGETTER(Pipe))    (BSTR      *aPipe);
    STDMETHOD(COMSETTER(Pipe))    (INPTR BSTR aPipe);
    STDMETHOD(COMGETTER(Server))  (BOOL      *aServer);
    STDMETHOD(COMSETTER(Server))  (BOOL       aServer);

    // public methods only for internal purposes
    bool isModified() { AutoLock alock (this); return mData.isBackedUp(); }
    bool isReallyModified() { AutoLock alock (this); return mData.hasActualChanges(); }
    bool rollback();
    void commit();
    void copyFrom (SerialPort *aThat);

    // public methods for internal purposes only
    // (ensure there is a caller and a read lock before calling them!)

    HRESULT loadSettings (CFGNODE aMachine, ULONG aSlot);
    HRESULT saveSettings (CFGNODE aMachine);

    // for VirtualBoxSupportErrorInfoImpl
    static const wchar_t *getComponentName() { return L"SerialPort"; }

private:

    const ComObjPtr <Machine, ComWeakRef> mParent;
    const ComObjPtr <SerialPort> mPeer;

    Backupable <Data> mData;
};

#endif // ____H_FLOPPYDRIVEIMPL
