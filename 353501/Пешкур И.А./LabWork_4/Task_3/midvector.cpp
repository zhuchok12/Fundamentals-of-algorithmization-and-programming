#include "midvector.h"
#include "ui_midvector.h"

MidVector::MidVector(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MidVector)
{
    ui->setupUi(this);

    ui -> tableWidget -> setColumnWidth( 0 , 260 );
    ui -> tableWidget -> setColumnWidth( 1 , 130 );

}

MidVector::~MidVector()
{
    delete ui;
}

void MidVector :: MakeMidVector( QString str )
{

    MakeVector( str );

    for( long long i = 0 ; i < OriginalVector.size() - OriginalVector.size() % 3 ; i += 3 )
    {

        if( ( OriginalVector[ i ] <= OriginalVector[ i + 1 ] && OriginalVector[ i ] >= OriginalVector[ i + 2 ] ) || ( OriginalVector[ i ] >= OriginalVector[ i + 1 ] && OriginalVector[ i ] <= OriginalVector[ i + 2 ] ) )
            MidVectorr.push_back( OriginalVector[ i ] );
        else if( ( OriginalVector[ i + 1 ] <= OriginalVector[ i ] && OriginalVector[ i + 1 ] >= OriginalVector[ i + 2 ] ) || ( OriginalVector[ i + 1 ] >= OriginalVector[ i ] && OriginalVector[ i + 1 ] <= OriginalVector[ i + 2 ] ) )
            MidVectorr.push_back( OriginalVector[ i + 1 ] );
        else
            MidVectorr.push_back( OriginalVector[ i + 2 ] );

    }

    if( OriginalVector.size() % 3 == 2 )
        MidVectorr.push_back( ( OriginalVector[ OriginalVector.size() - 1 ] + OriginalVector[ OriginalVector.size() - 2 ] ) / 2 );
    else if( OriginalVector.size() % 3 == 1 )
        MidVectorr.push_back( OriginalVector[ OriginalVector.size() - 1 ] );

    MakeTable();

}

void MidVector :: MakeVector( QString str )
{

    long long i = 0;
    long long value;

    while( i < str.length() )
    {

        value = 0;

        while( i < str.length() && str.at( i ).unicode() - 48 >= 0 && str.at( i ).unicode() - 48 < 10 && str.at( i ) != ' ' )
        {

            value = value * 10 + ( str.at( i ).unicode() - 48 );
            ++ i;

        }

        if( i >= str.length() || str.at( i ) == ' ' )
        {

            OriginalVector.push_back( value );

        }
        else
        {

            break;

        }

        while( i < str.length() && str.at( i ) == ' ' )
        {

            ++ i;

        }

    }

}

void MidVector :: MakeTable()
{

    ui -> tableWidget -> setRowCount( MidVectorr.size() );

    for( long long i = 0 ; i < OriginalVector.size() - OriginalVector.size() % 3 ; i += 3 )
    {

        QTableWidgetItem* item []= {

            new QTableWidgetItem( QString :: number( OriginalVector[ i ] ) + ", " + QString :: number( OriginalVector[ i + 1 ] ) + ", " + QString :: number( OriginalVector[ i + 2 ] ) ),
            new QTableWidgetItem( QString :: number(  MidVectorr[ i / 3 ] ) ),

        };

        ui -> tableWidget -> setItem( i / 3 , 0 , item[ 0 ] );
        ui -> tableWidget -> setItem( i / 3 , 1 , item[ 1 ] );

    }

    if( OriginalVector.size() % 3 == 2 )
    {

        QTableWidgetItem* item []= {

            new QTableWidgetItem( QString :: number( OriginalVector[ OriginalVector.size() - 2 ] ) + ", " + QString :: number( OriginalVector[ OriginalVector.size() - 1 ] ) ),
            new QTableWidgetItem( QString :: number(  MidVectorr[ MidVectorr.size() - 1 ] ) ),

        };

        ui -> tableWidget -> setItem( MidVectorr.size() - 1 , 0 , item[ 0 ] );
        ui -> tableWidget -> setItem( MidVectorr.size() - 1 , 1 , item[ 1 ] );

    }
    else if( OriginalVector.size() % 3 == 1 )
    {

        QTableWidgetItem* item []= {

            new QTableWidgetItem( QString :: number( OriginalVector[ OriginalVector.size() - 1 ] ) ),
            new QTableWidgetItem( QString :: number(  MidVectorr[ MidVectorr.size() - 1 ] ) ),

        };

        ui -> tableWidget -> setItem( MidVectorr.size() - 1 , 0 , item[ 0 ] );
        ui -> tableWidget -> setItem( MidVectorr.size() - 1 , 1 , item[ 1 ] );

    }

}
