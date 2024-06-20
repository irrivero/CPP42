/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:28:59 by irivero-          #+#    #+#             */
/*   Updated: 2024/06/20 17:52:13 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

    int	Account::_nbAccounts = 0;
    int	Account::_totalAmount = 0;
    int	Account::_totalNbDeposits = 0;
    int	Account::_totalNbWithdrawals = 0;

	void	Account::_displayTimestamp( void )
    {
        std::time_t t = std::time(0);
        std::tm *now = std::localtime(&t);
        std::cout << "[" << now->tm_year + 1900 << now->tm_mon + 1 << now->tm_mday << "_" << now->tm_hour << now->tm_min << now->tm_sec << "] ";
    }
	int	Account::getNbAccounts( void )
    {
        return (_nbAccounts);
    }
	int	Account::getTotalAmount( void )
    {
        return (_totalAmount);
    }
	int	Account::getNbDeposits( void )
    {
        return (_totalNbDeposits);   
    }
	int	Account::getNbWithdrawals( void )
    {
        return (_totalNbWithdrawals);
    }

    Account::Account( int initial_deposit )
    {
        
    }
    
	Account::~Account( void )
    {
        
    }

    void	Account::makeDeposit( int deposit )
    {
        
    }
	bool	Account::makeWithdrawal( int withdrawal )
    {
        
    }
	int		Account::checkAmount( void ) const
    {
        
    }
	void	Account::displayStatus( void ) const
    {
        
    }
    
	void	Account::displayAccountsInfos( void )
    {
        _displayTimestamp();
        std::cout << "accounts:" << getNbAccounts() << ";total:" << getNbDeposits() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << ";" << std::endl;
    }